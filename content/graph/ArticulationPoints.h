/**
 * Author: GitHub Copilot
 * License: CC0
 * Description: Encuentra puntos de articulacion (vertices de corte) en un grafo no dirigido.
 * Llama a una callback f(v) por cada vertice detectado. Maneja multiaristas
 * saltando solo una arista al padre.
 * Usage: articulation_points(g, [\&](int v){ ... })
 * Time: O(N + M)
 * Status: Tested
 */
#pragma once

vi tin_ap, low_ap; // tiempos de entrada y lowlink
vector<bool> vis_ap; // visitado
int Time_ap;

template<class G, class F>
void dfs_art(int v, int p, G& g, F& f) {
    vis_ap[v] = true;
    tin_ap[v] = low_ap[v] = ++Time_ap;

    int child = 0;
    bool parent_skipped = false; // soporta multiaristas v-p
    bool marked = false; // evita reportar v mas de una vez

    for (int to : g[v]) {
        if (to == p && !parent_skipped) { // saltar solo UNA arista al padre
            parent_skipped = true;
            continue;
        }
        if (vis_ap[to]) {
            low_ap[v] = min(low_ap[v], tin_ap[to]);
        } else {
            dfs_art(to, v, g, f);
            low_ap[v] = min(low_ap[v], low_ap[to]);
            if (p != -1 && low_ap[to] >= tin_ap[v] && !marked) {
                f(v); // v es punto de articulacion
                marked = true;
            }
            ++child;
        }
    }
    if (p == -1 && child >= 2) f(v); // raiz con >=2 hijos es articulacion
}

template<class G, class F>
void articulation_points(G& g, F f) {
    int n = sz(g);
    tin_ap.assign(n, -1);
    low_ap.assign(n, -1);
    vis_ap.assign(n, false);
    Time_ap = 0;
    rep(i,0,n) if (!vis_ap[i]) dfs_art(i, -1, g, f);
}
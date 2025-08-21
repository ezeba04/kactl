/**
 * Author: GitHub Copilot
 * License: CC0
 * Description: Encuentra puentes en un grafo no dirigido. Llama a una callback f(u, v)
 * por cada puente (u, v) detectado. Maneja multiaristas usando el truco de
 * saltar solo una arista al padre.
 * Usage: bridges(g, [\&](ll u, ll v){ ... })
 * Time: O(N + M)
 * Status: Tested
 */
#pragma once

vi tin_b, low_b;        // tiempos de entrada y lowlink
vector<bool> vis_b;     // visitado
int Time_b;

template<class G, class F>
void dfs_bridge(int v, int p, G& g, F& f) {
    vis_b[v] = true;
    tin_b[v] = low_b[v] = ++Time_b;

    bool parent_skipped = false;           // soporta multiaristas v-p
    for (int to : g[v]) {
        if (to == p && !parent_skipped) {  // saltar solo UNA arista al padre
            parent_skipped = true;
            continue;
        }
        if (vis_b[to]) {
            low_b[v] = min(low_b[v], tin_b[to]);
        } else {
            dfs_bridge(to, v, g, f);
            low_b[v] = min(low_b[v], low_b[to]);
            if (low_b[to] > tin_b[v]) f(v, to); // (v,to) es puente
        }
    }
}

template<class G, class F>
void bridges(G& g, F f) {
    int n = sz(g);
    tin_b.assign(n, -1);
    low_b.assign(n, -1);
    vis_b.assign(n, false);
    Time_b = 0;
    rep(i,0,n) if (!vis_b[i]) dfs_bridge(i, -1, g, f);
}
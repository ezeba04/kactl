/**
 * Author: Tu Nombre
 * Date: 2025-08-19
 * License: CC0
 * Source: Standard
 * Description: Prim (versión densa) para Árbol de Expansión Mínima (MST)
 *  sobre matriz de adyacencia (peso INF = sin arista). Devuelve el peso
 *  total del MST o -1 si el grafo es no conexo. used guarda pares (u,v)
 *  donde u es el padre de v en el MST.
 * Time: O(N^2)
 * Status: Untested
 */
#pragma once

const ll INF = 1e9;

ll primDense(const vector<vi>& adj,vector<pii>& used) {
    ll n = sz(adj);
    if (!n) return 0;
    used.clear();
    vi minW(n, INF), parent(n, -1);
    vector<bool> sel(n, 0);
    minW[0] = 0;
    ll total = 0;
    rep(it, 0, n) {
        ll v = -1;
        rep(i, 0, n) 
            if (!sel[i] && (v == -1 || minW[i] < minW[v])) 
                v = i;
        if (v == -1 || minW[v] == INF) return -1;
        sel[v] = 1;
        total += minW[v];
        if (parent[v] != -1) used.push_back({parent[v], v});
        rep(to, 0, n) if (!sel[to] && adj[v][to] < minW[to]) {
            minW[to] = adj[v][to];
            parent[to] = v;
        }
    }
    return total;
}
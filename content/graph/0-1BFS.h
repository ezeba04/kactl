/**
 * Author: Tu Nombre
 * Date: 2025-08-19
 * License: CC0
 * Source: Standard
 * Description: 0-1 BFS para grafos con pesos 0 o 1. Calcula distancias mínimas
 *  desde un origen y almacena padres para reconstruir caminos. Usa deque para
 *  mantener complejidad lineal.
 * Usage:
 *  vector<vector<pii>> adj(n);
 *  // adj[u].push_back({v, w}); // w in {0,1}
 *  vi d, p; zeroOneBFS(adj, src, d, p);
 *  // Reconstrucción camino a v:
 *  // for (ll x = v; x != -1; x = p[x]) path.push_back(x); reverse(all(path));
 * Time: $O(N + M)$
 * Memory: O(N)
 * Status: Untested
 */
#pragma once

const ll INF = 1000000000;

void zeroOneBFS(const vector<vector<pii>>& adj, ll s, vi& d, vi& p) {
    ll n = sz(adj);
    d.assign(n, INF);
    p.assign(n, -1);
    deque<ll> q;
    d[s] = 0;
    q.push_front(s);
    while (!q.empty()) {
        ll v = q.front(); q.pop_front();
        for (auto [to, w] : adj[v]) {
            if (d[v] + w < d[to]) {
                d[to] = d[v] + w;
                p[to] = v;
                if (w == 0) q.push_front(to);
                else        q.push_back(to);
            }
        }
    }
}
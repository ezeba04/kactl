/**
 * Author: Tu Nombre
 * Date: 2025-08-19
 * License: CC0
 * Source: Standard
 * Description: Dijkstra para grafos con pesos no negativos. Calcula
 *  distancias mínimas desde un origen y guarda padres para reconstruir
 *  caminos. Usa set (puede cambiarse a priority\_queue).
 * Usage:
 *  vector<vector<pii>> adj(n);
 *  // adj[u].push_back({v, w});
 *  vi d, p; dijkstra(adj, src, d, p);
 *  // Para reconstruir camino a v: for(ll x=v; x!=-1; x=p[x]) path.push_back(x);
 * Time: O((N + M) log N)
 * Memory: O(N)
 * Status: Untested
 */
#pragma once

const ll INF = 1000000000;

void dijkstra(const vector<vector<pii>>& adj, ll s, vi& d, vi& p) {
    ll n = (ll)adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    d[s] = 0;
    set<pii> q;
    q.insert({0, s});
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());
        for (auto [to, len] : adj[v]) {
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
/**
 * Author: Tu Nombre
 * Date: 2025-08-19
 * License: CC0
 * Source: Standard
 * Description: Dijkstra $O(N^2)$ para grafos con pesos no negativos. Util en grafos
 *  densos cuando $M \approx N^2$ y la version con heap no aporta mejora. Calcula distancias
 *  minimas desde un origen y almacena padres para reconstruccion de caminos.
 * Usage:
 *  vector<vector<pii>> adj(n);
 *  // adj[u].push_back({v, w});
 *  vi d, p; dijkstraDense(adj, src, d, p);
 *  // Reconstruccion camino a v:
 *  // for (ll x = v; x != -1; x = p[x]) path.push_back(x); reverse(path.begin(), path.end());
 * Time: $O(N^2 + M)$
 * Memory: O(N)
 * Status: Untested
 */
#pragma once

const ll INF = 1000000000;

void dijkstraDense(const vector<vector<pii>>& adj, ll s, vi& d, vi& p) {
    ll n = sz(adj);
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> used(n, false);
    d[s] = 0;
    rep(it, 0, n) {
        ll v = -1;
        rep(i, 0, n) if (!used[i] && (v == -1 || d[i] < d[v]))
                v = i;
        if (v == -1 || d[v] == INF) break;
        used[v] = 1;
        for (auto [to, len] : adj[v]) {
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}
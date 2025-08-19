/**
 * Author: Tu Nombre
 * Date: 2025-08-19
 * License: CC0
 * Source: Standard
 * Description: Prim (sparse) para MST con lista de adyacencia
 *  adj[u] = vector de (to, w). Devuelve peso total o -1 si no conexo.
 *  used guarda (padre, hijo).
 * Time: O(M log N)
 * Status: Untested
 */
#pragma once

const ll INF = 1000000000;

ll primSparse(const vector<vector<pii>>& adj, vector<pii>& used) {
  ll n = sz(adj);
  if (!n) return 0;
  used.clear();
  vi minW(n, INF), parent(n, -1);
  vector<bool> sel(n, false);
  set<pii> pq;  // (w, v)
  minW[0] = 0;
  pq.insert({0, 0});
  ll total = 0;
  while (!pq.empty()) {
    auto [w, v] = *pq.begin();
    pq.erase(pq.begin());
    if (sel[v]) continue;
    sel[v] = true;
    total += w;
    if (parent[v] != -1) used.push_back({parent[v], v});
    for (auto [to, wt] : adj[v])
      if (!sel[to] && wt < minW[to]) {
        if (minW[to] != INF) pq.erase({minW[to], to});
        minW[to] = wt;
        parent[to] = v;
        pq.insert({minW[to], to});
      }
  }
  rep(i, 0, n) if (!sel[i]) return -1;
  return total;
}
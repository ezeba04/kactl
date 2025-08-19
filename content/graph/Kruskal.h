/**
 * Author: Tu Nombre
 * Date: 2025-08-19
 * License: CC0
 * Source: Standard
 * Description: Kruskal para obtener el peso y las aristas del MST en un grafo
 *  no dirigido con pesos.
 * Time: O(M log M)
 * Status: Tested locally
 */
#pragma once

#include "../data-structures/UnionFind.h"

template<class T=ll>
struct Edge {
    ll u, v;
    T w;
    bool operator<(Edge const& o) const { return w < o.w; }
};

template<class T=ll>
T kruskal(ll N, vector<Edge<T>>& edges, vector<Edge<T>>& mst) {
    sort(all(edges));
    UF uf(N); T cost = 0;
    for (auto &e : edges) if (uf.join(e.u, e.v)) {
            cost += e.w;
            mst.push_back(e);
    }
    return cost;
}
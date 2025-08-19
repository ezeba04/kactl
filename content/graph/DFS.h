/**
 * Author: Tu Nombre
 * Date: 2025-08-19
 * License: CC0
 * Source: Standard
 * Description: DFS que registra tiempos de entrada (tin) y salida (tout) y colorea
 *  nodos: 0 = no visitado, 1 = en pila (gris), 2 = completado (negro). Util para
 *  detectar ciclos en dirigido, ordenar topologicamente (los tout en orden
 *  decreciente), probar ancestralidad ($u$ es ancestro de $v$ si
 *  $tin[u] \le tin[v] \land tout[v] \le tout[u]$) y otras tareas.
 * Time: $O(N + M)$
 * Memory: O(N) (pila de recursion)
 * Status: Untested
 */
#pragma once

// Requiere globals definidos externamente:
// vector<vi> adj; vi color, tin, tout; int timer = 0;
// color: 0 no visitado, 1 gris, 2 negro.
void dfs(ll v) {
    tin[v] = timer++;
    color[v] = 1;
    for (ll u : adj[v])
        if (color[u] == 0)
            dfs(u);
    color[v] = 2;
    tout[v] = timer++;
}
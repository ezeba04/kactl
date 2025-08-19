/**
 * Author: Your Name
 * Date: 2025-08-19
 * License: CC0
 * Source: Classic
 * Description: Busqueda binaria sobre un arreglo ordenado a[0..n-1]. El
 *  invariante mantenido es a[l] <= k < a[r]. Inicia con l = -1, r = n.
 *  Al terminar (r - l == 1), se cumple:
 *    - l: indice del ultimo elemento <= k (o -1 si todos > k)
 *    - r: indice del primer elemento > k (o n si todos <= k)
 *  Se proveen funciones auxiliares para patrones comunes.
 * Usage:
 *  int l = last_leq(a, k);          // ultimo <= k
 *  int r = first_gt(a, k);          // primer > k
 *  int pos = first_geq(a, k);       // primer >= k
 *  bool exists =
 *      (first_geq(a, k) < (int)a.size() \&\&
 *       a[first_geq(a, k)] == k);
 * Time: O(log N)
 * Status: Tested locally
 */
#pragma once

// Devuelve indice del primer elemento > k (n si no existe)
template<class T, class U>
int first_gt(const vector<T>& a, const U& k) {
    int n = (int)a.size();
    int l = -1, r = n;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (k < a[m]) r = m;      // a[l] <= k < a[m] <= a[r]
        else l = m;               // a[l] <= a[m] <= k < a[r]
    }
    return r;
}

// Devuelve indice del ultimo elemento <= k (-1 si no existe)
template<class T, class U>
int last_leq(const vector<T>& a, const U& k) {
    int n = (int)a.size();
    int l = -1, r = n;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (a[m] <= k) l = m;
        else r = m;
    }
    return l;
}

// Primer indice >= k (n si no existe)
template<class T, class U>
int first_geq(const vector<T>& a, const U& k) {
    int n = (int)a.size();
    int l = -1, r = n;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (a[m] < k) l = m;      // a[l] < k <= a[r]
        else r = m;
    }
    return r;
}

// ultimo indice < k (-1 si no existe)
template<class T, class U>
int last_lt(const vector<T>& a, const U& k) {
    int n = (int)a.size();
    int l = -1, r = n;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (a[m] < k) l = m;      // a[l] < k <= a[r]
        else r = m;
    }
    return l;
}
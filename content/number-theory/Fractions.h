/**
 * Author: Ezequiel Bacher (+GPT)
 * Date: 2025-08-22
 * License: CC0
 * Description: Fracción racional con normalización por gcd y aritmética exacta
 *  sobre enteros. Mantiene el denominador positivo y la forma reducida.
 * Time: O(1) por operación
 * Status: not-tested
 * Details: Realiza cancelación mediante gcd para mitigar overflow. Aun así,
 *  puede desbordar si los productos intermedios no entran en int. Considera
 *  cambiar a long long si fuera necesario.
 */
#pragma once

struct frac {
  int p, q;
  frac(int p = 0, int q = 1) : p(p), q(q) { norm(); }
  void norm() {
    int a = gcd(p, q);
    if (a) p /= a, q /= a;
    else q = 1;
    if (q < 0) q = -q, p = -p;
  }
  frac operator+(const frac& o) const {
    int a = gcd(o.q, q);
    return frac(p * (o.q / a) + o.p * (q / a), q * (o.q / a));
  }
  frac operator-(const frac& o) const {
    int a = gcd(o.q, q);
    return frac(p * (o.q / a) - o.p * (q / a), q * (o.q / a));
  }
  frac operator*(frac o) const {
    int a = gcd(o.p, q), b = gcd(p, o.q);
    return frac((p / b) * (o.p / a), (q / a) * (o.q / b));
  }
  frac operator/(frac o) const {
    int a = gcd(o.q, q), b = gcd(p, o.p);
    return frac((p / b) * (o.q / a), (q / a) * (o.p / b));
  }
  bool operator<(const frac& o) const { return 1LL * p * o.q < 1LL * o.p * q; }
  bool operator==(const frac& o) const { return p == o.p && q == o.q; }
};
/**
 * Author: Ezequiel Bacher (+GPT)
 * Date: 2025-08-21
 * License: CC0
 * Description: Criba para rapida factorizacion.
 * Time: $O(N * log(log (N)) + log(Q))$
 * Status: not-tested
 * Details: Despite its n log log n complexity, segmented sieve is still faster
 * than other options, including bitset sieves and linear sieves. This is
 * primarily due to its low memory usage, which reduces cache misses. This
 * implementation skips even numbers.
 */
#pragma once

struct PrimeSieve {
    ll N;
    vi sp;

    PrimeSieve(int _N) : N(_N), sp(N+1, -1) {
        rep(i,2,N+1) {
            if (sp[i] == -1) {
                sp[i] = i;
                for (ll j = i * i; j <= N; j += i) {
                    if (sp[j] == -1) sp[j] = i;
                }
            }
        }
    }

    vi factorize(ll x) const {
        vi f;
        while (x > 1) {
            f.push_back(sp[x]);
            x /= sp[x];
        }
        return f;
    }
    
    bool isPrime(ll x){
        return x == sp[x];
    }
};
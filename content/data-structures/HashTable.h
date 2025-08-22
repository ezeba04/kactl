/**
 * Author: KACTL contributors (adapted)
 * Date: 2025-08-22
 * License: CC0
 * Description: Hasher para vi para usar con unordered_set/map. Misma
 *  estructura que HashMap.h, con ejemplo de uso.
 */
#pragma once

struct Hash {
    size_t operator()(const vi& v) const {
        size_t s = 0;
        for (auto& e : v)
            s ^= hash<int>()(e) + 0x9e3779b9 + (s << 6) + (s >> 2);
        return s;
    }
};

// Puedes cambiar a unordered_map<vi, T, Hash> si necesitas valores.
unordered_set<vi, Hash> s;
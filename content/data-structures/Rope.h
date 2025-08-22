/**
 * Author: GitHub Copilot
 * Date: 2025-08-22
 * License: CC0
 * Source: GCC libstdc++ ext
 * Description: A sequence container with O(log N) random access, insert, erase at any position.
 * Supports efficient concatenation, substring, and in-place modification via mutable references.
 * Time: O(log N) per access/insert/erase
 * Status: Tested locally
 */
#pragma once

#include <ext/rope> /** keep-include */
using namespace __gnu_cxx;

template<class T>
using Rope = rope<T>;

void example() {
    Rope<int> s, t;
    s.push_back(8);
    s.push_back(4);
    t.push_back(1);
    s.append(t); // concat at the end

    s.insert(1, 9); // insert element at position 1
    s.insert(2, t); // insert rope t at position 2

    auto sub = s.substr(1, 2); // [1, 3)
    s.erase(0, 1); // erase first element

    int x = s[0]; // read-only access
    s.mutable_reference_at(0) = x + 1; // modify in place

    // Note: begin()/end() are const iterators. 
    // Use mutable_begin()/mutable_end() to allow modification.
}
/**
 * Author: E-Zeba
 * License: CC0
 * Description: Finds the maximum subarray sum.
 * The subarray must be non-empty.
 * Handles negative numbers.
 * Time: O(N)
 * Status: Tested
 */
#pragma once

template<class I>
I kadane(const vector<I>& v) {
    if (v.empty()) return 0;
    I max_so_far = v[0], current_max = v[0];
    for (size_t i = 1; i < v.size(); ++i) {
        current_max = max(v[i], current_max + v[i]);
        max_so_far = max(max_so_far, current_max);
    }
    return max_so_far;
}
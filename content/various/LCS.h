/**
 * Author: GitHub Copilot
 * License: CC0
 * Description: Length of the Longest Common Subsequence (LCS) between two sequences, using rolling DP.
 * Time: O(N M)
 * Status: lightly tested
 */
#pragma once

template<class T>
ll lcs(const vector<T>& A, const vector<T>& B) {
    if (A.empty() || B.empty()) return 0;
    vi dp(sz(B) + 1), prv(sz(B) + 1);
    rep(i,0,sz(A)) {
        swap(dp, prv);
        rep(j,0,sz(B)) {
            dp[j+1] = (A[i] == B[j]) ? prv[j] + 1 : max(prv[j+1], dp[j]);
        }
    }
    return dp[sz(B)];
}
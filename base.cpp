#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "codes/debug.h"
#else
#define debug(...)
#endif

using ll = int64_t;
#define sz(x) ((int)(x).size())
const char nl = '\n';
#define __ freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases = 1;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve();
    return 0;
}
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#endif

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>; 

using ordered_multiset = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>; 
//erase x in multiset a -> a.erase(a.find_by_order(a.order_of_key(x)))

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ordered_map<int, int> my_map;

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

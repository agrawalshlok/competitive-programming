#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

#ifdef LOCAL
#include "codes/debug.h"
#else
#define debug(...)
#endif

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>; 
// find_by_order() and order_of_key(). 
//The first returns an iterator to the k-th largest element (counting from zero)
//the second — the number of items in a set that are strictly smaller than our item.

using ordered_multiset = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>; 
//erase x in multiset a -> a.erase(a.find_by_order(a.order_of_key(x)))

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ordered_map<int, int> my_map;


using ll = int64_t;
#define sz(x) ((int)(x).size())
const char nl = '\n';
#define __ freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main () {
  ordered_set os;
  os.insert (10);
  int x = rng() ;
}

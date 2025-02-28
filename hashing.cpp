#include <bits/stdc++.h>
using namespace std;

// for int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
#define safe_map unordered_map<long long, int, custom_hash>
#define safe_set unordered_set<int, custom_hash>
#define hashmap gp_hash_table<int, int, custom_hash>

// for pair
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(pair<uint64_t, uint64_t> x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1);
  }
};

#define safe_map unordered_map<pair<int, int>, int, custom_hash>
#define safe_set unordered_set<pair<int, int>, custom_hash>
#define hashmap gp_hash_table<int, int, custom_hash>

// rolling hash
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
constexpr uint64_t mod = (1ull << 61) - 1;
uint64_t modmul(uint64_t a, uint64_t b) {
  uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
  uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
  uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
  ret = (ret & mod) + (ret >> 61);
  ret = (ret & mod) + (ret >> 61);
  return ret - 1;
}
const int64_t B = uniform_int_distribution<int64_t>(0, mod - 1)(rng);

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int M1 = 998244353;
const int M2 = 999999937;
const int B1 = uniform_int_distribution<int64_t>(0, M1 - 1)(rng);
const int B2 = uniform_int_distribution<int64_t>(0, M2 - 1)(rng);
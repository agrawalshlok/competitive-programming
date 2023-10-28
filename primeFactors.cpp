#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// Log(n) time complexity after running seive for number smaller than 1e7 
const int nax = 1e7+5;
const int MAXN = nax;
vector<int> spf(nax); 
void sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++) spf[i] = i;
    for (int i = 4; i < MAXN; i += 2) spf[i] = 2;
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
vector<int> factorization (int x) { // gives unique prime factors
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

// for larger numbers sqrt(n) time complexity
vector<ll> primefac(ll n) {
    vector<ll> primef;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            primef.push_back(i);
        }
    }
    if(n != 1) primef.push_back(n);
    return primef;
}

// all divisors O(sqrt(n))
set<ll> divisors(ll n) {
    set<ll> x;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) x.insert(i);  
            else {
                x.insert(i); 
                x.insert(n / i);
            }
        }
    }
    return x;
}
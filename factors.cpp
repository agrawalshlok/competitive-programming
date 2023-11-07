#include <bits/stdc++.h>
using namespace std;

// Log(n) time complexity after running seive for numbers smaller than 1e7 
const int MAXN = (int)1e7 + 5;
vector<int> spf (MAXN); 

void sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++) 
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2) 
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> primeFactorization (int x) { 
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

// for larger numbers sqrt(n) time complexity
vector<int> primefac (int n) { // gives unique prime factors
    vector<int> primef;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) 
                n /= i;

            primef.push_back(i);
        }
    }

    if (n != 1) 
        primef.push_back(n);

    return primef;
}

// all divisors O(sqrt(n)). Unsorted
vector<int> divisors (int n) {
    vector<int> x;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {
                x.push_back(i);  
            } else {
                x.push_back(i); 
                x.push_back(n / i);
            }
        }
    }

    return x;
}

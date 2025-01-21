#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int find_first_false(const vector<bool>& b) {
    int l = -1; // min - 1
    int r = (int)b.size(); // max + 1
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (b[m]) 
            l = m;
        else
            r = m;
    }
    return r;
    // for TTTTFFFFF -> r returns the first false, l returns the last true
}

bool search(int x[], int n, int k) {
    int l = 0, r = n-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (x[m] == k) return true;
        if (x[m] < k) l = m+1; else r = m-1;
    }
    return false;
}
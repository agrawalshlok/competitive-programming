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

void binary_search_on_answer(ll tc) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    //sortA(a);
    ll l = a[n - 1], r = 1e10;
    while(r > l) {
        ll mid = (r + l) / 2, curr = 0;
        for(ll i = 0; i < n; i++) curr += mid - a[i];
        if(curr >= mid) r = mid;
        else l = mid + 1;
    }
    cout << r << "\n";
    /*
    for FFFFTTT -- to find the first true
    for TTTTFFF distribution -- to find the last true
    while(l < r) {
        ll mid = (l + r + 1) / 2;
        if(mid is true) l = mid;
        else r = mid - 1
    }
    cout << r << nl;
    */
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
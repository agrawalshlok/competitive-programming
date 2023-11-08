#include <bits/stdc++.h>
using namespace std;

vector<int> lis (vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d (n + 1, INF);
    vector<int> p (n + 1, -1), idx (n + 1, -1);
    d[0] = -INF;
 
    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l]) { // min val for length l
            d[l] = a[i];
            idx[l] = i;
            p[i] = idx[l - 1];
        }
    }
 
    vector<int> ret;
    for (int l = n; l >= 0; l--) {
        if (d[l] < INF) {
            ret.push_back (idx[l]);
            int par = p[idx[l]];
            while (par > -1) {
                ret.push_back (par);
                par = p[par]; 
            }
 
            break;
        }
    }

    reverse (ret.begin (), ret.end());
    for (int i = 0; i < (int)ret.size(); i++) 
        ret[i] = a[ret[i]];
 
    return ret;
}
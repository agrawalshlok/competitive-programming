#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define nl "\n"

const int inf = INT_MAX;
struct node {
	int mn = inf, mx = inf, val = 0;
	node() : mn(inf), mx(-inf), val(0) {}; // neutral value (doesn't interfere if combined with actual answer)
};
struct SegTree {
	int N;
	vector<node> st;
	vector<bool> cLazy;
	vector<int> lazy;
	void init(int n) {
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}
	void merge(node &cur, node &l, node &r) {
		cur.mn = min(l.mn, r.mn), cur.mx = max(l.mx, r.mx), cur.val = l.val + r.val; // this is the normal function which you want to do for parents using left and right child
	}
	void propagate(int ver, int L, int R) {
		if (L != R) {
			cLazy[ver * 2] = cLazy[ver * 2 + 1] = 1;
			lazy[ver * 2] += lazy[ver], lazy[ver * 2 + 1] += lazy[ver]; 
		}   
        st[ver].mn += lazy[ver], st[ver].mx += lazy[ver], st[ver].val += (R - L + 1) * lazy[ver]; // during lazy propagation you have to chg this line according to the condition
		cLazy[ver] = 0;
        lazy[ver] = 0;
	}
	void build(int ver, int L, int R, vector<int> &a) {
		if (L > R) return;
		if (L == R) {
			st[ver].mn = a[L - 1], st[ver].mx = a[L - 1], st[ver].val = a[L - 1]; // add here if new variables
			return;
		}
		int M = (L + R) / 2;
		build(ver * 2, L, M, a), build(ver * 2 + 1, M + 1, R, a);
		merge(st[ver], st[ver * 2], st[ver * 2 + 1]);
	}
	node Query(int ver, int L, int R, int i, int j) {
		if (cLazy[ver]) {
			propagate(ver, L, R);
		}
		if (j < L || i > R) {
			return node();
		}
		if (i <= L && R <= j) {
			return st[ver];
		}
		int M = (L + R) / 2;
		node left = Query(ver * 2, L, M, i, j), right = Query(ver * 2 + 1, M + 1, R, i, j), cur;
		merge(cur, left, right);
		return cur;
	}
	void Update(int ver, int L, int R, int i, int j, int val) {
		if (cLazy[ver]) {
			propagate(ver, L, R);
		}
		if (j < L || i > R) {
			return;
		}
		if (i <= L && R <= j) {
			cLazy[ver] = 1, lazy[ver] += val; // change if set
			propagate(ver, L, R);
			return;
		}
		int M = (L + R) / 2;
		Update(ver * 2, L, M, i, j, val), Update(ver * 2 + 1, M + 1, R, i, j, val);
		merge(st[ver], st[ver * 2],st[ver * 2 + 1]);
	}

	node query(int l, int r) {
		return Query(1, 1, N, l, r);
	}
	void update(int l, int r, int val) {
		Update(1, 1, N, l, r, val);
	}
};
int main(void) {
	SegTree st;
	int n;
	cin >> n;
    st.init(n);
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	st.build(1, 1, n, arr);      // 1 indexing
	for(int i = 0; i < 4 * n; i++){
        cout << st.st[i].mn << " " << st.st[i].mx << " " << i << nl;
    }
	//st.query(1,3) // for getting mimimum or maximum from 1 to 3 index starting from 1.  [1,3] 
}

	// Alternate Query
	// node Query(int ver, int l, int r, int i, int j) {
	// 	if(l >= i && j >= r) {
	// 		return st[ver];
	// 	}
	// 	int mid = (l + r) / 2;
	// 	node ret;
	// 	if (mid >= j) {
	// 		ret = Query(ver * 2, l, mid, i, j);
	// 	} else if (mid < i) {
	// 		ret = Query(ver * 2 + 1, mid + 1, r, i, j);
	// 	} else {
	// 		node left = Query(ver * 2, l, mid, i, j);
	// 		node right = Query(ver * 2 + 1, mid + 1, r, i, j);
	// 		merge(ret, left, right, mid, mid + 1);
	// 	}
	// 	return ret;
	// }	

	// point update
	// void Update(int ver, int L, int R, int pos, ll val) {
	// 	if(cLazy[node])
	// 		propagate(node, L, R);
	// 	if (L == R) {
    //         st[ver].mx = val;
    //         st[ver].idx = L;
    //         st[ver].val = val;
	// 		return;
	// 	}
	// 	int M = (L + R)/2;
	// 	if(pos <= M)
	// 		Update(ver * 2, L, M, pos, val);
	// 	else
	// 		Update(ver * 2 + 1, M + 1, R, pos, val);

	// 	node tleft = Query (2 * ver, L, M, L, M);
	// 	node tright = Query(2 * ver + 1, M + 1, R, M + 1, R);
	// 	merge (st[ver], tleft, tright);
	// }
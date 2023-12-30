#include <bits/stdc++.h> 
using namespace std;

const int inf = INT_MAX;
struct node {
	int mn = inf, mx = inf, val = 0;
	node() : mn(inf), mx(-inf), val(0) {}; // neutral value (doesn't interfere if combined with actual answer)
};

struct SegmentTree { // 1-based indexing
	int N;
	vector<node> st;
	vector<bool> cLazy;
	vector<int> lazy;

	SegmentTree (vector<int> &a) {
		N = a.size();
		st.resize (4 * N + 5);
		cLazy.assign (4 * N + 5, false);
		lazy.assign (4 * N + 5, 0);
        	Build (1, 1, N, a);
    	}

	void merge (node &cur, node &l, node &r) {
		cur.mn = min(l.mn, r.mn), cur.mx = max(l.mx, r.mx), cur.val = l.val + r.val; // this is the normal function which you want to do for parents using left and right child
	}

	void propagate (int ver, int L, int R) {
		if (L != R) {
			cLazy[ver * 2] = cLazy[ver * 2 + 1] = 1;
			lazy[ver * 2] += lazy[ver], lazy[ver * 2 + 1] += lazy[ver]; 
		}   
        	st[ver].mn += lazy[ver], st[ver].mx += lazy[ver], st[ver].val += (R - L + 1) * lazy[ver]; // during lazy propagation you have to chg this line according to the condition
		cLazy[ver] = 0;
        	lazy[ver] = 0;
	}

	void Build (int ver, int L, int R, vector<int> &a) {
		if (L > R) return;
		if (L == R) {
			st[ver].mn = a[L - 1], st[ver].mx = a[L - 1], st[ver].val = a[L - 1]; // add here if new variables
			return;
		}
		int M = (L + R) / 2;
		Build(ver * 2, L, M, a), Build(ver * 2 + 1, M + 1, R, a);
		merge(st[ver], st[ver * 2], st[ver * 2 + 1]);
	}

	node Query (int ver, int L, int R, int i, int j) {
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

	void Update (int ver, int L, int R, int i, int j, int val) {
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

	node query (int l, int r) {
		return Query(1, 1, N, l, r);
	}

	void update (int l, int r, int val) {
		Update(1, 1, N, l, r, val);
	}
};

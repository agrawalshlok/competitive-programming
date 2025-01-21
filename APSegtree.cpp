struct node {
	int val = 0;
	node() : val(0) {}; 
};

struct SegmentTree { // 1-based indexing
	int N;
	vector<node> st;
	vector<bool> cLazy;
	vector<pair<int,int>> lazy;

	SegmentTree (vector<int> &a) {
		N = a.size();
		st.resize (4 * N + 5);
		cLazy.assign (4 * N + 5, false);
		lazy.assign (4 * N + 5, {0, 0});
        Build (1, 1, N, a);
    }

	void merge (node &cur, node &l, node &r) {
		cur.val = l.val + r.val;
	}

	void propagate (int ver, int L, int R) {
		if (L != R) {
			cLazy[ver * 2] = cLazy[ver * 2 + 1] = 1;
			lazy[ver * 2].first += lazy[ver].first, lazy[ver * 2].second += lazy[ver].second;
			lazy[ver * 2 + 1].first += ((((R + L) / 2) - L + 1) * lazy[ver].second) + lazy[ver].first, lazy[ver * 2 + 1].second += lazy[ver].second;
		}   

		st[ver].val += (R - L + 1) * (2 * lazy[ver].first + (R - L) * lazy[ver].second) / 2;
		cLazy[ver] = 0;
        lazy[ver] = {0, 0};
	}

	void Build (int ver, int L, int R, vector<int> &a) {
		if (L > R) return;
		if (L == R) {
			st[ver].val = a[L - 1]; 
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

	void Update (int ver, int L, int R, int i, int j, pair<int,int> val) {
		if (cLazy[ver]) {
			propagate(ver, L, R);
		}
		if (j < L || i > R) {
			return;
		}
		if (i <= L && R <= j) {
			cLazy[ver] = 1, lazy[ver].first += (val.first + (L - i) * val.second), lazy[ver].second = val.second;
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

	void update (int l, int r, pair<int,int> val) {
		Update(1, 1, N, l, r, val);
	}
};
const int inf = INT_MAX;
struct node {
  int mn = inf, mx = inf, val = 0;
  node() : mn(inf), mx(-inf), val(0) {}; // neutral value (doesn't interfere if combined with actual answer)
};

struct SegmentTree { // 1-based indexing
  int N;
  vector<node> st;

  SegmentTree (vector<int> &a) {
    N = a.size();
    st.resize (4 * N + 5);
        Build (1, 1, N, a);
    }

  void merge (node &cur, node &l, node &r) {
    cur.mn = min(l.mn, r.mn), cur.mx = max(l.mx, r.mx), cur.val = l.val + r.val; // this is the normal function which you want to do for parents using left and right child
  }

  void Build (int ver, int L, int R, vector<int> &a) {
    if (L > R) return;
    if (L == R) {
      st[ver].mn = a[L - 1], st[ver].mx = a[L - 1], st[ver].val = a[L - 1]; // add here if new variables
      return;
    }
    int M = (L + R) / 2;
    Build (ver * 2, L, M, a), Build (ver * 2 + 1, M + 1, R, a);
    merge (st[ver], st[ver * 2], st[ver * 2 + 1]);
  }

  node Query (int ver, int L, int R, int i, int j) {
    if (j < L || i > R) {
      return node();
    }
    if (i <= L && R <= j) {
      return st[ver];
    }
    int M = (L + R) / 2;
    node left = Query (ver * 2, L, M, i, j), right = Query (ver * 2 + 1, M + 1, R, i, j), cur;
    merge (cur, left, right);
    return cur;
  }

  void Update (int ver, int L, int R, int pos, int val) {
    if (L == R) {
            st[ver].mx = val;
            st[ver].mn = val;
            st[ver].val = val;
      return;
    }

    int M = (L + R)/2;
    if (pos <= M)
      Update(ver * 2, L, M, pos, val);
    else
      Update(ver * 2 + 1, M + 1, R, pos, val);

    node tleft = Query (2 * ver, L, M, L, M);
    node tright = Query(2 * ver + 1, M + 1, R, M + 1, R);
    merge (st[ver], tleft, tright);
  }

  node query (int l, int r) {
    return Query(1, 1, N, l, r);
  }

  void update (int pos, int val) {
    Update (1, 1, N, pos, val);
  }
};

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

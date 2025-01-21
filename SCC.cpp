class SCC { // 1-based indexing
public:
  int n;
  vector<vector<int>> adj;
  vector<vector<int>> adjtranspose;
  vector<bool> visited;
  stack<int> st;
  vector<int> color; // colors are 0 to c-1
  vector<vector<int>> components; // Beware of Multi-edge between two SCC's
  int c = 0;               // number of colors

  SCC (int r) {         // pass the exact number of nodes n from 1 to n in consideration.
    n = r;
    adj.resize(r + 5);
    adjtranspose.resize(r + 5);
    visited.resize(r + 5, false);
    color.resize(r + 5, -1);
    c = 0;
  }

  void add_edge (int u, int v) {
    adj[u].push_back(v);
    adjtranspose[v].push_back(u);
  }
  
  void dfs1 (int node) {
    visited[node] = true;
    for (auto x : adj[node]) {
      if (!visited[x])
        dfs1(x);
    }
    st.push(node);
  }

  void dfs2(int node, int col) {
    visited[node] = true;
    color[node] = col;
    for (auto x : adjtranspose[node]) {
      if (!visited[x])
        dfs2(x, col);
    }
  }

  void condense_directed_graph() { // adj and adjtranspose should already be constructed before calling this function
    for (int i = 1; i <= n; i++) {
      if (!visited[i])
        dfs1(i);
    }

    visited.assign (n + 5, false);
    while (!st.empty()) {
      int x = st.top();
      st.pop();
      if (!visited[x])
        dfs2(x, c++);
    }

    components.resize(c);
    for (int i = 1; i <= n; i++) {
      for (auto x : adj[i]) {
        if (color[i] != color[x])
          components[color[i]].push_back(color[x]);
      }
    }
  }
};
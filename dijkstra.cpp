vector<vector<pair<int,int>>> adj(n); 
int dis[n] = INF;

priority_queue<pair<int,int>> pq;
pq.push({0, x});
dis[x] = 0;

while (!pq.empty()) {
  auto [w, u] = pq.top();
  pq.pop();
  w *= -1;
  if (dis[u] != w) 
    continue;

  for (auto [v, wt]: adj[u]) {
    if (dis[v] > wt + w) {
      dis[v] = wt + w;
      pq.push({-(wt + w), v});
    }
  } 
}
const int N = 505;
vector<int> g[N];
int capacity[N][N];
int n,m;
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, 1e18});
 
    while (q.size()) {
        auto [u,flow] = q.front();
        q.pop();
        for (int next : g[u]) {
            if (parent[next] == -1 && capacity[u][next]) {
                parent[next] = u;
                int new_flow = min(flow, capacity[u][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}
 
int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n + 1);
    int new_flow;
 
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
 
    return flow;
}
const int N = 1e3+5;
vector<int> g[2 * N];
int c[2 * N][2 * N];
int n,m,k;
int bfs(int s, int t, vector<int> &parent){
    fill(parent.begin(), parent.end(), - 1);
    queue<pair<int, int>> q;
    q.push({s,1e9});
    parent[s] = 0;
    int cnt = 0;
    while(q.size()){
        auto [u,flow] = q.front();
        q.pop();
        for (auto v : g[u]){
            if(parent[v] == -1 && c[u][v]){
                parent[v] = u;
                int new_flow = min(c[u][v], flow);
                if(v == t){
                    return new_flow;
                }
                q.push({v,new_flow});
            }
        }
    }

    return 0;
}
int max_flow(int s, int t){
    int flow = 0;
    vector<int> parent(m + n + 5);
    int new_flow;
    while(new_flow = bfs(s,t,parent)){
        int cur = t;
        while(cur != s){
            int prev = parent[cur];
            c[prev][cur] -= new_flow;
            c[cur][prev] += new_flow;
            cur = prev;
        }
        flow += new_flow;
    }

    return flow;
}
void run_case(){
        cin >> n >> m >> k;
    for (int i = 1; i <= k; i++){
        int u,v;
            cin >> u >> v;
        g[u].push_back(v + n);
        g[v + n].push_back(u);
        c[u][v + n] = 1;
    }

    for (int i = 1; i <= n; i++){
        g[0].push_back(i);
        g[i].push_back(0);
        c[0][i] = 1;
        //c[i][0] = 1;
    }

    for (int i = 1; i <= m; i++){
        g[m + n + 1].push_back(i + n);
        g[i + n].push_back(m + n + 1);
        c[i + n][m + n + 1] = 1;
    }

   cout << max_flow(0,m + n + 1);
}
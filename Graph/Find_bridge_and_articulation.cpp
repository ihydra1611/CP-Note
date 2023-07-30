const int N = 1e5 + 20, M = 2e5 + 20;
vector<int> g[N];
int low[N], num[N];
int cnt , bridge, articulation;
void dfs(int u, int p){
    num[u] = low[u] = ++cnt;
    int node = (u != p);

    for (auto v : g[u]){
        if(v == p) continue;
        if(!num[v]){
            dfs(v, u);
            low[u] = min(low[v], low[u]);
            if(low[v] == num[v]){
                bridge++;
            }

            if(low[v] >= num[u]){
                node++;
            }
        } else{
            low[u] = min(low[u], num[v]);
        }

        
    }

    articulation += (node >= 2);
}
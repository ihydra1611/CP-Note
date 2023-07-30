const int N = 1e5 + 20, M = 2e5 + 20;
vector<int> g[N], q;
int low[N], num[N], cnt,  cc;
void dfs(int u){
    num[u] = low[u] = ++cnt;
    q.push_back(u);
    for (auto v : g[u]){
        if(!num[v]){
            dfs(v);
            low[u] = min(low[v], low[u]);
        } else{
            low[u] = min(low[u], num[v]);
        }        
    }

    if(low[u] == num[u]){
        int v = 0;
        cc++;
        while(v != u){
            v = q.back();
            q.pop_back();
            num[v] = low[v] = N;
        }
    }
}
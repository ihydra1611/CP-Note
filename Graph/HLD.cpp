const int N = 1e5+5;
vector<int> g[N];
int heavy[N], group[N], parent[N], depth[N], id[N];
int dfs(int u, int p){
    int mx = 0, cnt = 1;
    for (auto v : g[u]){
        if(v == p) continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        int c = dfs(v,u);
        if(c > mx){
            mx = c;
            heavy[u] = v;
        }
        cnt +=  c;
    }
    return cnt;
}
int cnt = 1;
void decompose(int u, int p){
    id[u] = cnt++;
    group[u] = p;
    if(!heavy[u]) return;
    decompose(heavy[u], p);
    for (auto v : g[u]){
        if(parent[u] == v || v ==  heavy[u]) continue;
        decompose(v,v);
    }
}
 
Segment_tree<int, _max, 0> e(N);
 
void update(int a, int b, int val){
    while(group[a] != group[b]){
        if(depth[group[a]] < depth[group[b]]) swap(a,b);
        e.update(id[group[a]], id[a],val);
        a = parent[group[a]];
    }
    
    if(depth[a] > depth[b]) swap(a, b);
    e.update(id[a],id[b],val);
}
 
int query(int a, int b){
    int res = 0;
    while(group[a] != group[b]){
        if(depth[group[a]] < depth[group[b]]) swap(a,b);
        res = max(res, e.get(id[group[a]], id[a]));
        a = parent[group[a]];
    }
    
    if(depth[a] > depth[b]) swap(a, b);
    res = max(res, e.get(id[a],id[b]));
 
    return res;
}
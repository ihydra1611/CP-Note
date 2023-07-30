const int N = 1e5 + 5;
int fa[N], sz[N];
int find(int u){
    return (u == fa[u] ? u : fa[u] = find(fa[u]));
}

bool merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;

    if(sz[u] < sz[v]) swap(u,v);
    fa[v] = u;
    sz[u] += sz[v];

    return true;
}
struct Egde{
    int u, v, c;
};
void run_case(){
    int n, m;
        cin >> n >> m;
    for (int i = 1; i <= n; i++){
        sz[i] = 1;
        fa[i] = i;
    }
    vector<Egde> v(m);
    for (auto &i : v){
        cin >> i.u >> i.v >> i.c ;
    }  

    sort(v.begin(), v.end(), [](Egde &a, Egde &b){
        return a.c < b.c;
    });

    int ans = 0;
    for (auto [u,v,c] : v){
        if(merge(u, v)){
            ans += c;
        }
    }
    cout << ans << el;
}
/*
    Kuhn's Algorithm - Maximum Bipartite Matching
    Usage: Matching e(max(l,r));
        + l,r: size of 2 group
    Note: index from 1
*/
struct Matching{
    int n;
    vector<vector<int>> g;
    vector<int> vis;
    vector<int> p;
    Matching(int n): n(n),g(2 * n + 5), vis(2 * n + 5), p(2 * n + 5){};

    void add(int u, int v){
        g[u].push_back(v + n);
        g[v + n].push_back(u);
    }

    bool dfs(int u){
        if(vis[u]) return 0;
        vis[u] = 1;
        for (auto v : g[u]){
            if(p[v] == -1 || dfs(p[v])){
                p[v] = u;
                p[u] = v;
                return 1;
            }
        }

        return 0;
    }

    int match(){
        int res = 0;
        
        fill(p.begin(), p.end(), -1);

        while(1){
            fill(vis.begin(), vis.end(), 0);
            bool cont = 0;
            for(int i = 1; i <= n; i++){
                if(p[i] == -1) cont |= dfs(i);
            }
            if(cont == 0)break;
        }

        for (int i = 1; i <= n; i++){
            if(p[i] != -1){
                res++;
            }
        }
        return res;
    }
};

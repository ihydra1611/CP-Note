struct Sparse_table{
    vector<vector<int>> g;
    int n;
    Sparse_table(vector<int> &v){
        g.resize(20);
        g[0] = v;
        n = v.size();
        for (int i = 0; i < 20; i++) g[i].resize(1e6 + 5);

        for (int i = 1; i <= log2(n); i++){
            for (int j = 1; j + (1 << i) - 1 <= n; j++){
                g[i][j] = min(g[i - 1][j], g[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int get(int l, int r){
        int x = log2(r - l + 1);
        return min(g[x][l], g[x][r - (1 << x) + 1]);
    }
};
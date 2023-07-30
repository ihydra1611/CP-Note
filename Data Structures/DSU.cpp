struct DSU{
    int n;
    vector<int> par;
    vector<int> size;

    DSU(int n) : n(n), par(n + 5), size(n + 5){
        for (int i = 0 ; i <= n; i++){
            par[i] = i;
            size[i] = 1;
        }
    };

    void merge(int a,int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] < size[b]) swap(a,b);
            par[b] = a;
            size[a] += size[b];
        }
    }

    int find(int v){
        return (v == par[v] ? v : par[v] = find(par[v]));
    }
};
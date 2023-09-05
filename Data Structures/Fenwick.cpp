struct Fenwick{
    int n;
    vector<int> a;
    Fenwick(int n) : n(n), a(n + 5){
        for (int i = 1; i <= n; i++) a[i] = 0;
    }

    void add(int i, int val){
        if(i == 0) return;
        for (; i <= n; i += (i & -i)){
            a[i] += val;
        }
    }

    int prefix(int i){
        int res = 0;
        for (; i ; i -= (i & -i)){
            res += a[i];
        }
        return res;
    }

    int get(int l, int r){
        return prefix(r) - prefix(l - 1);
    }

};
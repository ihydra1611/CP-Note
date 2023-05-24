struct Fenwick{
    int n;
    vector<int> a;
    Fenwick(int n) : n(n), a(n + 5){
        for (int i = 1; i <= n; i++) a[i] = 0;
    }

    void update(int i, int val){
        for (; i <= n; i += (i & -i)){
            a[i] += val;
        }
    }

    int getSum(int i){
        int res = 0;
        for (; i ; i -= (i & -i)){
            res += a[i];
        }
        return res;
    }

    int query(int l, int r){
        return getSum(r) - getSum(l - 1);
    }

};

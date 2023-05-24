struct Fenwick{
    int n;
    vector<int> bit1, bit2;
    Fenwick(int n) : n(n), bit1(n + 5), bit2(n + 5){};


    void update(vector<int> &a, int i, int val){
        for (; i <= n; i += (i & -i)){
            a[i] += val;
        }
    }

    void updateRange(int l, int r, int v) {
        update(bit1, l, (n - l + 1) * v);
        update(bit1, r + 1, -(n - r) * v);
        update(bit2, l, v);
        update(bit2, r + 1, -v);
    }

    int getSum(vector<int> &a, int i){
        int res = 0;
        for (; i ; i -= (i & -i)){
            res += a[i];
        }
        return res;
    }

    int prefixSum(int u) {
        return getSum(bit1, u) - getSum(bit2, u) * (n - u);
    }

    int query(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }

};


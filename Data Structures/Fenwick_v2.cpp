struct Fenwick{
    int n;
    vector<int> bit1, bit2;
    Fenwick(int n) : n(n), bit1(n + 5), bit2(n + 5){};


    void add(vector<int> &a, int i, int val){
        if(i == 0) return;
        for (; i <= n; i += (i & -i)){
            a[i] += val;
        }
    }

    void add(int l, int r, int v) {
        add(bit1, l, (n - l + 1) * v);
        add(bit1, r + 1, -(n - r) * v);
        add(bit2, l, v);
        add(bit2, r + 1, -v);
    }

    int prefixSum(vector<int> &a, int i){
        int res = 0;
        for (; i ; i -= (i & -i)){
            res += a[i];
        }
        return res;
    }

    int prefix(int u) {
        return prefixSum(bit1, u) - prefixSum(bit2, u) * (n - u);
    }

    int get(int l, int r) {
        return prefix(r) - prefix(l - 1);
    }

};
struct Matrix{
    vector<vector<int>> v;
    int n;
    Matrix(int n){
        this->n = n;
        init(n);
    }

    Matrix(vector<vector<int>> &in){
        v = in;
        n = v[0].size();
    }
    void init(int n){
        v.resize(n);
        for(int i = 0; i < n; i++){
            v[i].resize(n);
        }
    }

    Matrix operator* (const Matrix &other){
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++){
                    ans[i][j] += v[i][k] * other.v[k][j] % mod;
                    ans[i][j] %= mod;
                }
        return Matrix(ans);
    }

    Matrix pow(int p){
        if(p == 1) return *this;
        Matrix tmp = pow(p / 2);
        tmp = tmp * tmp;
        return (p & 1 ? tmp * v : tmp);
    }
};
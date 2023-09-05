/*
    Usage: RMQ<int, _min> rmq(v);
    v: vector
    index from 1 -> n
*/
template<typename T, T (*op) (T,T)>
struct RMQ{
    RMQ(const vector<int> &v) : t{v}, n((int)v.size()){
        for (int k = 1; (1 << k) <= n; k++){
            t.emplace_back(n - (1 << k) + 5);
            for (int i = 1; i + (1 << k)  - 1 <= n; i++){
                t[k][i] = op(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
            }
        }
    };

    T get(int l, int r){
        int k = log2(r - l + 1);
        return op(t[k][l], t[k][r - (1 << k) + 1]);
    }

    private:
        vector<vector<T>> t;
        int n;
};
template<typename  T> T _min(T a, T b) { return b < a ? b : a; }
template<typename  T> T _max(T a, T b) { return a < b ? b : a; }
template<typename  T> T _gcd(T a, T b) { return gcd(a,b); }
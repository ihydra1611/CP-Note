template<typename T, T (*op)(T, T), T lim>
struct Segment_tree{
    vector<T> g;
    int n;
    Segment_tree(int n){
        g.resize(4 * n + 5);    
        this->n = n;
    };
 
 
    void update(int id,int l, int r, int pos, T val){
        if(l == r) {
            g[id] = val;
            return;
        }
 
        int mid = (l + r) >> 1;
        if(pos <= mid) update(id << 1, l, mid, pos, val);
        else update(id << 1 | 1, mid + 1, r, pos, val);
 
        g[id] = op(g[id << 1], g[id << 1 | 1]);
    }
 
 
    T get(int id, int l, int r, int u ,int v){
        if(l > v || r < u) return lim;
        if(l >= u && r <= v){
            return g[id];
        }
 
        int mid = (l + r) >> 1;
        return op(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
 
    void update(int pos, int val){
        update(1, 1, n, pos, val);
    }
 
    T get(int l, int r){
        return get(1, 1, n, l, r);
    }
};
template<class T> T _min(T a, T b) { return b < a ? b : a; }
template<class T> T _max(T a, T b) { return a < b ? b : a; }
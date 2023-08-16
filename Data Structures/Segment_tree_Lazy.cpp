template<typename T>
struct Node{
    T val, lazy;
};

template<typename T, T (*op)(T, T), T lim>
struct Segment_tree{
    vector<Node<int>> g;
    int n;
    Segment_tree(int n){
        g.resize(4 * n + 5);    
        this->n = n;
    };


    void down(int id){
        T t = g[id].lazy;
        g[id << 1].lazy += t;
        g[id << 1].val += t;
        g[id << 1 | 1].lazy += t;
        g[id << 1 | 1].val += t;
        g[id].lazy = 0;
    }


    void update(int id,int l, int r, int u, int v, T val){
        if(l > v || r < u) return;
        if(l >= u && r <= v) {
            g[id].val += val;
            g[id].lazy += val;
            return;
        }
        int mid = (l + r) >> 1;
        down(id);
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        g[id].val = op(g[id << 1].val, g[id << 1 | 1].val);
    }


    T get(int id, int l, int r, int u ,int v){
        if(l > v || r < u) return lim;
        if(l >= u && r <= v){
            return g[id].val;
        }

        int mid = (l + r) >> 1;
        down(id);
        return op(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }

    void update(int l, int r, int val){
        update(1,1,n,l,r, val);
    }

    T get(int l, int r){
        return get(1,1,n,l,r);
    }
};
template<class T> T _min(T a, T b) { return b < a ? b : a; }
template<class T> T _max(T a, T b) { return a < b ? b : a; }
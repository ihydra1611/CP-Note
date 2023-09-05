struct Wavelet_tree{
    int lo, hi, L, R, x = -1;
    Wavelet_tree *left, *right;
    vector<int> b;

    Wavelet_tree(vector<int> &v){
        int mi = *min_element(v.begin(), v.end());
        int mx = *max_element(v.begin(), v.end());
        *this = Wavelet_tree(v,1,(int)v.size() - 1,mi, mx);
    }

    Wavelet_tree(vector<int> &v, int l, int r, int mi, int mx){
        lo = mi; hi = mx;
        if(lo == hi || l > r) {
            return;
        }

        int mid = (lo + hi) >> 1;
        auto f = [&](int x){
            return x <= mid;
        };

        b.push_back(0);
        for (int i = l; i <= r; i++){
            b.push_back(b.back() + f(v[i]));
        }

        
        auto p =  stable_partition(v.begin() + l, v.begin() + r + 1, f) - v.begin();
        left = new Wavelet_tree(v,l, p - 1, lo, mid);
        right = new Wavelet_tree(v,p, r, mid + 1, hi);
    }




    // // count K in [l,r]
    int count(int l, int r, int k){
        if(l > r || k > hi || k < lo) return 0;
        if(lo == hi) {
            return r - l + 1;
        }

        int lb = b[l - 1], rb = b[r];
        int mid = (lo + hi) >> 1;
        if(k <= mid) {
            return this->left->count(lb + 1, rb, k);
        }
        else {
            return this->right->count(l - lb, r - rb, k);
        }
    }

    //count less or equal to K in [L, R]
    int count_less_or_equal(int l, int r, int k){
        if(l > r || k < lo) return 0;
        if(k >= hi) return r - l + 1;

        int mid = (lo + hi) >> 1;
        int lb = b[l - 1], rb = b[r];

        return this->left->count_less_or_equal(lb + 1, rb, k)
               + this->right->count_less_or_equal(l - lb, r - rb, k);
        
    }
};
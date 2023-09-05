template<class T>
struct Compress{
    vector<T> v;
    Compress(vector<T> &in):v(in){
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
    };

    int get_pos(int val){
        int res = lower_bound(v.begin(), v.end(), val) - v.begin();
        return (res != v.size() && v[res] == val ? res : -1);
    }
};
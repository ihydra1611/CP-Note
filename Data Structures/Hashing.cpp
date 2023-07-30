struct Hashing{
    vector<int> h;
    vector<int> p;
    Hashing(string s, int mod){
        s = "$" + s;
        h.resize(s.size());
        p.resize(s.size());
        p[0] = 1;

        for (int i = 1; i < s.size(); i++){
            p[i] = p[i - 1] * 131 % mod;
        }

        h[0] = 0;
        for (int i = 1; i < s.size(); i++){
            h[i] = (h[i - 1] * 131  + s[i]) % mod;
        }
    }

    int get(int l , int r){
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod * mod) % mod;
    }
};
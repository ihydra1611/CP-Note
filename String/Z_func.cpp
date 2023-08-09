struct Z_func{
    vector<int> z;
    Z_func(string s){
        z.resize(s.size());
        int l = 0, r = 0;
        for (int i = 1; i < s.size(); i++){
            if(i <= r){
                z[i] = min(r - i + 1, z[i - l]);
            } 
            while(i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) z[i]++;
            if(i + z[i] - 1> r){
                l = i;
                r = i + z[i] - 1;
            }
        };
    }

};
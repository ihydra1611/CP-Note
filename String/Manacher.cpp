struct Manacher{
    string s,tmp;
    vector<int> p;
    string change(string s){
        string res = "$";
        for (auto i : s){
            res += "#";
            res += i;
        }
        return res + "#@";
    }
 
    void build(string in){
        s = in;
        tmp = change(s);
        p.resize(tmp.size() + 5);
        int l = 1, r = 1;
        for (int i = 1; i < tmp.size(); i++){
            if(r > i){
                int m = l - (i - l);
                p[i] = min(r - i, p[m]);
            }
 
            while(tmp[i + 1 + p[i]] == tmp[i - 1 - p[i]]) p[i]++;
            if(i + p[i] > r){
                l = i;
                r = i + p[i];
            }  
        }
    }
 
    void getAll(){
        for (int i = 2; i < tmp.size(); i++){
            if(p[i] > 0){
                cout << s.substr((i - p[i]) / 2, p[i]) << el;
            }
        }
    }
 
    
};
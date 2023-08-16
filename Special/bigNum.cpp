struct Z{
    string s;
    Z& f(int n){
        this->s = to_string(n);
        return *this;
    }

    Z& f(string x){
        this->s = x;
        return *this;   
    };

    Z(string x){
        f(x);
    };
    Z(int x){ f(x); };
    Z(){ f(0); };

    bool operator < (const Z &other){
        if(s == other.s) return 0;
        if(s[0] != '-' && other.s[0] == '-') return 0;
        if(s[0] == '-' && other.s[0] != '-') return 1;

        int f = (s[0] == '-');
        if((s.size() == other.s.size() && s < other.s) || s.size() < other.s.size()){
            return (1 ^ f);
        } else return (0 ^ f);
    }


    bool operator > (const Z &other){
        if(s == other.s) return 0;
        if(s[0] != '-' && other.s[0] == '-') return 1;
        if(s[0] == '-' && other.s[0] != '-') return 0;

        int f = (s[0] == '-');
        if((s.size() == other.s.size() && s > other.s) || s.size() > other.s.size()){
            return 1 ^ f;
        } else return 0 ^ f;
    }


    bool operator >= (const Z &other){return !(*this < other);}
    bool operator <= (const Z &other){return !(*this > other);}
    bool operator == (const Z &other){return s == other.s;}
    bool operator != (const Z &other){return s != other.s;}

    void operator += (const Z &other){*this = *this + other;};
    void operator -= (const Z &other){*this = *this - other;};
    void operator *= (const Z &other){*this = *this * other;};
    void operator /= (const Z &other){*this = *this / other;};
    void operator %= (const Z &other){*this = *this % other;};

    Z operator + (const Z &other){
        string a = s; reverse(a.begin(), a.end());
        string b = other.s; reverse(b.begin(), b.end());
 
        while((int)a.size() < (int)b.size()) a += '0';
        while((int)b.size() < (int)a.size()) b += '0';

        int du = 0;
        string ans;
        ans.resize(a.size());
        for (int i = 0 ; i < ans.size(); i++){
            int sum = a[i] + b[i] + du - 2 * '0';
            ans[i] = sum % 10 + '0';
            du = sum / 10;
        }

        if(du){
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }


    Z operator - (const Z &other){
        string a = s; 
        string b = other.s; 
        int check = 0;
        if((a.size() == b.size() && a < b) || a.size() < b.size()){
            swap(a,b);
            check = 1;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while((int)a.size() < (int)b.size()) a += '0';
        while((int)b.size() < (int)a.size()) b += '0';
        
        int du = 0;
        string ans;
        ans.resize(a.size());

        for (int i = 0; i < ans.size(); i++){
            int d = a[i] - b[i] - du;
            if(d < 0){
                d += 10;
                du = 1;
            } else du = 0;
            ans[i] = d + '0';
        }
        while(ans.back() == '0' && ans.size() > 1) ans.pop_back();

        if(check) ans += '-';
        reverse(ans.begin(), ans.end());
        return ans;
    }
    

    Z operator* (const Z &other){
        string a = s;
        string b = other.s;
        if(a == "0" || b == "0") return 0;

        Z p[10];
        for(int i = 1; i <= 9; i++){
            p[i] = p[i - 1] + s;
        }


        Z ans;
        string tmp;
        for (int i = 0; i + 1< b.size(); i++) tmp += '0';
        int n = b.size() - 1;
        for (auto i : b){
            Z x = p[i - '0'];
            x.s += tmp;
            ans = ans + x;
            tmp.pop_back();
        }
        return ans;
    }

    Z operator/ (const Z &other){return div(s, other.s).first;}
    Z operator% (const Z &other){return div(s, other.s).second;}

    pair<string, string> div(const string &a, const string &b){
        if(b == "0"){
            return {"nan","nan"};
        }
        Z p[10];
        for(int i = 1; i <= 9; i++){
            p[i] = p[i - 1] + b;
        }
        Z ans;
        Z tmp;
        
        for (auto i : a){
            tmp = tmp * 10 + (i - '0');
            int x = 9;
            while(x && tmp < p[x]) x--;
            if(!x && ans == 0) continue;
            ans = ans * 10 + x;
            tmp -= p[x];
        }
        return {ans.s, tmp.s};
    }



    friend istream &operator>>(istream &in, Z &x) { 
         in >> x.s;
         return in;            
    }


    friend ostream &operator<<(ostream &out,const Z &x){
        out << x.s;
        return out;
    }

};
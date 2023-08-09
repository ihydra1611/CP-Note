using mint = ModInt;
struct ModInt{
    int a;
    ModInt& s(int vv){
        a = (vv < mod ? vv : vv - mod);
        return *this;
    }
 
    ModInt(int x = 0){s(x % mod + mod);}
 
    ModInt& operator+=(const ModInt &x){return s(a + x.a);}
    ModInt& operator-=(const ModInt &x){return s(a + mod - x.a);}
    ModInt& operator*=(const ModInt &x){
        a = a * x.a % mod;
        return *this;
    }
    ModInt& operator/=(const ModInt &x){
        *this *= x.inv();
        return *this;
    }
 
    ModInt operator+ (const ModInt &x)const{return ModInt(*this) += x;}
    ModInt operator- (const ModInt &x)const{return ModInt(*this) -= x;}
    ModInt operator* (const ModInt &x)const{return ModInt(*this) *= x;}
    ModInt operator/ (const ModInt &x)const{return ModInt(*this) /= x;}
    bool operator== (const ModInt &x)const{return a == x.a;}
    bool operator!= (const ModInt &x)const{return a != x.a;}
    bool operator< (const ModInt &x)const{return a < x.a;}
 
    ModInt operator-()const{return ModInt() - *this;}
    ModInt pow(int n)const{
        ModInt res(1),x(*this);
        while(n){
            if(n&1)res*=x;
            x*=x;
            n>>=1;
        }
        return res;
    }
    ModInt inv()const{return pow(mod-2);}

    friend istream& operator>>(istream& in, ModInt& a){
        return (in >> a.a);
    }
    
    friend ostream& operator<<(ostream& out,const ModInt& a){
        return (out<<a.a);
    }
    
};
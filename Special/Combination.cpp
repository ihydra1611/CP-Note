const int N = 1e6+5;
int fac[N];
int inv_fac[N];
int __pow(int a, int p){
    if(p == 1) return a;

    int t = __pow(a, p / 2);
    t *= t;
    t %= mod;
    return (p & 1 ? (t * a) % mod : t);
}

int C(int n, int k){
    return ((fac[n] * inv_fac[k]) % mod * inv_fac[n - k]) % mod;
}

void build(){
    fac[0] = inv_fac[0] = 1;
    for (int i = 1; i <= 1000000; i++){
        fac[i] = (fac[i - 1] * i) % mod;
        inv_fac[i] = __pow(fac[i], mod - 2);
    }
}
const int N = 2e5;
struct node{
    int l, r;
} t[N * 20];

int cnt,L,R;
int rt[105];
void add(int &id, int l, int r, int pos){
    if(!id){
        id = ++cnt;
    }
    if(l == r){
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) add(t[id].l,l, mid, pos);
    else add(t[id].r, mid + 1, r,pos);
};

int merge(int x, int y){
    if(!x || !y){
        return x + y;
    }
    t[y].l = merge(t[x].l, t[y].l);
    t[y].r = merge(t[x].r, t[y].r);
    return y;
};

void change(int &d, int &p, int l, int r){
    if(!d) return;
    if(L <= l && r <= R){
        p = merge(d,p);
        d = 0;
        return;
    }

    if(!p) p = ++cnt;

    int mid = (l + r) >> 1;
    if(mid >= L) change(t[d].l, t[p].l, l, mid);
    if(mid < R) change(t[d].r, t[p].r, mid + 1, r);
}
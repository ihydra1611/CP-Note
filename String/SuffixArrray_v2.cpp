struct SuffixArray {
    vector<int> sa, lcp, rank;
    SuffixArray(string& s, int lim = 256){
        int n = s.size() + 1, k = 0, a, b;
        vector<int> x(s.begin(), s.end() + 1), y(n), ws(max(n, lim));
        sa = lcp = y;

        iota(sa.begin(), sa.end(), 0);
        
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p){
            p = j;
            iota(y.begin(), y.end(), n - j);

            for (int i = 0; i < n; i++) {
                if (sa[i] >= j) y[p++] = sa[i] - j;
            }

            fill(ws.begin(), ws.end(), 0);
            for (int i = 0; i < n; i++) ws[x[i]]++;
            for (int i = 1; i < lim; i++) ws[i] += ws[i-1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            
            swap(x, y), p = 1, x[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                a = sa[i - 1]; 
                b = sa[i]; 
                x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1: p++;
            }
        }

        rank.resize(n);
        for (int i = 1; i < n; i++) {
            rank[sa[i]] = i;
        }

        for (int i = 0, k = 0; i < n; i++){
            if(rank[i] != n - 1){
                for (int j = sa[rank[i] + 1]; max(i + k, j + k) < n && s[i + k] == s[j + k];){
                    k++;
                }
                lcp[rank[i]] = k;
                if(k) k--;
            }
        }
    }
};
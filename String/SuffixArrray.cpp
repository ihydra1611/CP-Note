struct SuffixArray {
    string s;
    int n;
    vector<int> sa, rank, temp, lcp;

    SuffixArray(){};

    void all(string &input){
        s = input + "$";
        n = s.size();
        sa.resize(n);
        rank.resize(n);
        temp.resize(n);
        buildSA();
        buildLCP();
    }

    void countingSort(int k){
        int maxn = max(300LL,n);
        vector<int> c(maxn);
        for (int i = 0 ; i < n; i++){
            c[i + k < n? rank[i + k] : 0]++;
        }

        for (int i = 0, sum = 0; i < maxn; ++i) {
            int t = c[i]; 
            c[i] = sum; 
            sum += t;
        }

        vector<int> tmpSA(n);
        for (int i = 0; i < n; i++){
            tmpSA[c[sa[i] + k < n ? rank[sa[i] + k] : 0]++] = sa[i];
        }
        sa = tmpSA;
    }
    void buildSA() {
        for (int i = 0; i < n; ++i) {
            sa[i] = i;
            rank[i] = s[i];
        }

        
        for (int k = 1; k < n; k *= 2) {
            auto cmp = [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];
                a = (a + k >= n) ? -1 : rank[a + k];
                b = (b + k >= n) ? -1 : rank[b + k];
                return a < b;
            };
            countingSort(k);
            countingSort(0);
            temp[sa[0]] = 0;
            for (int i = 1; i < n; ++i) {
                temp[sa[i]] = temp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
            }
            rank = temp;
        }
    }


    void buildLCP(){
        lcp.resize(n);
        for (int i = 0, k = 0; i < n; i++){
            if(rank[i] != n - 1){
                for (int j = sa[rank[i] + 1];max(i + k, j + k) < n && s[i + k] == s[j + k];){
                    k++;
                }
                lcp[rank[i]] = k;
                if(k) k--;
            }
        }
    }

    int calc_unique_substr(){
        int res = n - sa[n - 1] - 1;
        for (int i = n - 2; i >= 0; i--){
            res += n - sa[i] - lcp[i] - 1;
        }
        return res;
    }

    vector<int> exactly_k_times(){
        vector<int> lenS;   lenS.push_back(0);
        vector<int> cntS;   cntS.push_back(0);
        vector<int> cnt(n + 5);
        int n = s.size() - 1;
        
        for (int i = n; i >= 0; i--){
            while(lenS.back() > lcp[i]){
                int l = lenS.back();
                int c = cntS.back();
                lenS.pop_back();
                cntS.pop_back();

                int k = max(lenS.back(), lcp[i]);
                cnt[c] += l - k;

                if(lenS.back() == l) {
                    cntS.back() += c;
                } else{
                    lenS.push_back(k);
                    cntS.push_back(c);
                }
            }
            lenS.push_back(n - sa[i]);
            cntS.push_back(1);
        }
        return cnt;
    }
};
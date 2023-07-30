struct Node{
    int start, end;
    int len;
    int child[26];
    int suffixLink;
    int cnt;
};
struct Palimerome_Tree{
    vector<Node> tree;
    string s;
    int cntNode;
    int cur;
    void build(string in){
        s = in;
        tree.resize(s.size() + 5);
        cntNode = 2;
        cur = 1;
        tree[1].len = -1; tree[1].suffixLink = 1;
        tree[2].len = 0;  tree[2].suffixLink = 1;
        for (int i = 0; i < s.size(); i++){
            insert(i);
        }
    }

    void insert(int id){
        // add node
        int tmp = cur;
        while(1){
            int curLen = tree[tmp].len;
            if(id - curLen - 1 >= 0 && s[id - curLen - 1] == s[id]){
                break;
            }
            tmp = tree[tmp].suffixLink;
        }

        if(tree[tmp].child[s[id] - 'a'] != 0){
            cur = tree[tmp].child[s[id] - 'a'];
            return;
        }

        cntNode++;
        tree[tmp].child[s[id] - 'a'] = cntNode;
        tree[cntNode].start = id - tree[tmp].len - 1;
        tree[cntNode].end = id;
        tree[cntNode].len = tree[tmp].len + 2;


        // add suffixLink
        cur = cntNode;
        tmp = tree[tmp].suffixLink;

        if(tree[cur].len == 1){
            tree[cur].suffixLink = 2;
            return;
        }
        while(1){
            int curLen = tree[tmp].len;
            if(id - curLen - 1 >= 0 && s[id - curLen - 1] == s[id]){
                break;
            }
            tmp = tree[tmp].suffixLink;
        }

        tree[cur].suffixLink = tree[tmp].child[s[id] - 'a'];
    }

    vector<string> getList(){
        vector<string> res;
        for (int i = 3; i <= cntNode; i++){
            res.push_back(s.substr(tree[i].start, tree[i].len));
        }
        return res;
    }

    void showAll(){
        for (int i = 3; i <= cntNode; i++){
            cout << s.substr(tree[i].start, tree[i].len) << el; 

        }
    }

};
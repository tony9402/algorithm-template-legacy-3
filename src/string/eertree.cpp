//title: EER TREE
//prefix: eertree, palitree
//description: EER TREE (https://arxiv.org/pdf/1506.04862.pdf)
template<typename T = int> struct EERTREE {
    struct Node {
        int len, suffix_link;
        T cnt;
        map<char, int> nxt;
        
        Node() : Node(0, 0) { }
        Node(int _len, int _link) {
            len = _len; suffix_link = _link;
            cnt = T();
        }
    };

    vector<Node> tree;
    int cnt, last_suffix;

    EERTREE(int N) {
        tree.resize(N);
        cnt = last_suffix = 2;
        tree[1] = Node(-1, 1);
        tree[2] = Node(0, 1);
    }
    void init(const string &S) {
        for(int i = 0; i < (int)S.size(); ++i) {
            int cur = last_suffix;
            while(1) {
                if(i - tree[cur].len - 1 >= 0 && S[i - tree[cur].len - 1] == S[i]) break;
                cur = tree[cur].suffix_link;
            }
            if(tree[cur].nxt.count(S[i])) {
                last_suffix = tree[cur].nxt[S[i]];
                ++ tree[last_suffix].cnt;
                continue;
            }
            last_suffix = tree[cur].nxt[S[i]] = ++cnt;
            int nxt = cnt;
            tree[nxt].len = tree[cur].len + 2;
            ++ tree[nxt].cnt;
            if(tree[nxt].len == 1) {
                tree[nxt].suffix_link = 2;
                continue;
            }
            while(cur > 1) {
                cur = tree[cur].suffix_link;
                if(i - tree[cur].len - 1 >= 0 && S[i - tree[cur].len - 1] == S[i]) {
                    tree[nxt].suffix_link = tree[cur].nxt[S[i]];
                    break;
                }
            }
        }
    }
    Node& operator[](const int &idx) { return tree[idx]; }
};
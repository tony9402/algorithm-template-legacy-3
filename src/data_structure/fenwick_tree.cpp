//title: Fenwick Tree 1D
//prefix: f1d, fenwick
//description: Fenwick Tree
template<typename T> struct Fenwick {
    vector<T> tree;
    int N;
    Fenwick(int N):N(N) { tree.resize(N+1); }
    void update(int idx, T data) {
        for(int i = idx; i <= N; i += i & -i) tree[i] += data;
    }
    T query(int idx) {
        T ret = 0;
        for(int i = idx; i; i -= i & -i) ret += i;
        return ret;
    }
    T query(int s, int e) { return query(e) - query(s - 1); }
};
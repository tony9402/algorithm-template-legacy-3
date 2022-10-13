//title: Segment Tree With Lazy Propagation
//prefix: seglazy, segmentlazy
//description: Segment Tree with Lazy Propagation
template<typename T> struct SegmentLazy {
    vector<T> tree;
    vector<T> lazy;
    int siz;
    SegmentLazy(int N = 1 << 17) {
        for(siz = 1; siz <= N; siz <<= 1);
        tree.resize(siz << 1);
        lazy.resize(siz << 1);
    }
    void propagate(int l, int r, int pos) {
        if(!lazy[pos]) return;
        if(l != r) {
            lazy[pos << 1] += lazy[pos];
            lazy[pos << 1 | 1] += lazy[pos];
        }
        tree[pos] += (r - l + 1) * lazy[pos];
        lazy[pos] = 0;
    }
    void update(int l, int r, int s, int e, int pos, T data) {
        if(s <= l && r <= e) {
            lazy[pos] += data;
            propagate(l, r, pos);
            return;
        }
        propagate(l, r, pos);
        if(e < l || r < s) return;
        int mid = (l + r) / 2;
        update(l, mid, s, e, pos << 1, data);
        update(mid + 1, r, s, e, pos << 1 | 1, data);
        tree[pos] = merge(tree[pos << 1], tree[pos << 1 | 1]);
    }
    void update(int s, int e, T data) { update(0, siz - 1, s, e, 1, data); }
    T query(int l, int r, int s, int e, int pos) {
        propagate(l, r, pos);
        if(s <= l && r <= e) return tree[pos];
        if(e < l || r < s) return T();
        int mid = (l + r) / 2;
        return merge(query(l, mid, s, e, pos << 1), query(mid + 1, r, s, e, pos << 1 | 1));
    }
    T query(int s, int e) { return query(0, siz - 1, s, e, 1); }
    T merge(T a, T b) { return a + b; }
};

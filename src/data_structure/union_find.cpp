//title: Union Find
//prefix: uf, unionfind
//description: Union Find (No Rollback)
struct UnionFind {
    vector<int> uf, siz;
    UnionFind(int N) {
        uf.resize(N,-1);
        siz.resize(N,0);
    }
    int find(int x) { return uf[x] < 0 ? x : uf[x] = find(uf[x]); }
    bool merge(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;
        uf[b] = a;
        siz[a] += siz[b];
        return true;
    }
};
//title: SuffixArray(Nlog^2N)
//prefix: sa, suffixarray
//description: Graph
template<typename T> struct SuffixArrayLCP { // O(Nlog^2N)
    vector<int> sa, pos, tmp, lcp;
    SuffixArray(const T& S) {
        int N = (int)S.size();
        sa = pos = tmp = vector<int>(N);
        for(int i = 0; i < N; ++i) sa[i] = i, pos[i] = S[i];
        for(int d = 1; ; d <<= 1) {
            function<bool(int, int)> cmp = [&](int a, int b) -> bool {
                if(pos[a] != pos[b]) return pos[a] < pos[b];
                if(a + d < N && b + d < N) return pos[a + d] < pos[b + d];
                return a > b;
            };
            sort(sa.begin(), sa.end(), cmp);
            for(int i = 1; i < N; ++i) tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
            for(int i = 0; i < N; ++i) pos[sa[i]] = tmp[i];
        }
        buildLCP(S);
    }
    void buildLCP(const T& S) {
        for(int i = 0, k = 0; i < N; ++i, k = max(0, k - 1)) {
            while(sa[pos[i] - 1] + k < N && sa[pos[i]] + k < N && S[sa[pos[i] - 1] + k] == S[sa[pos[i]] + k]) ++k;
            lcp[pos[i]] = k;
        }
    }
};

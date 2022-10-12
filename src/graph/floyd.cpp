//title: Floyd with Traceback
//prefix: floyd
//description: Floyd O(N^3) with Traceback
template<typename T> struct Floyd {
    const T INF = numeric_limits<T>::max() / 2;
    vector<vector<T>> DP;
    vector<vector<int>> path;
    int N;
    Floyd(int N):N(N) {
        DP = vector<vector<T>>(N, vector<T>(N, INF));
        path = vector<vector<int>>(N, vector<int>(N, -1));
        for(int i=0;i<N;++i) DP[i][i]=0;
    }
    void addEdge(int u, int v, int w) { DP[u][v] = min(DP[u][v], w); }
    void floyd() {
        for(int k = 0; k < N; ++k) {
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    if(DP[i][j] > DP[i][k] + DP[k][j]) {
                        DP[i][j] = DP[i][k] + DP[k][j];
                        path[i][j] = k;
                    }
                }
            }
        }
    }
    vector<int> getPath(int S, int E) {
        vector<int> ret;
        if(S==E || DP[S][E] == INF)return ret;
        function<void(int,int)> findPath = [&](int s, int e) -> void {
            int pre = path[s][e];
            if(!~pre) return;
            findPath(s,pre); 
            ret.push_back(pre);
            findPath(pre,e);
        };
        ret.push_back(S);
        findPath(S, E);
        ret.push_back(E);
        return ret;
    }
    vector<T>& operator[](const int &idx) { return DP[idx]; }
};
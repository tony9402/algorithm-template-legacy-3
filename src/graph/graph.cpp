//title: Graph Basic Tempalte
//prefix: graph
//description: Graph
template<typename T> struct Graph {
    vector<vector<T>> G;
    Graph(int N) { G.resize(N + 1); }
    void addEdge(int u, T data) { G[u].emplace_back(data); }
    int size() { return (int)G.size(); }
    vector<T>& operator[](const int &idx) { return G[idx]; }
};

//title: Dijkstra
//prefix: dijk, dijkstra
//description: Dijkstra
template<typename T> struct Dijkstra {
    const T INF = numeric_limits<T>::max();
    Graph<pair<int, T>> G;
    int N;
    Dijkstra(Graph<pair<int, T>> G):G(G) { N = (int)G.size(); }
    vector<T> dijkstra(int S) {
        vector<T> dist(N, INF);
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;
        pq.emplace(dist[S] = 0, S);
        while(!pq.empty()) {
            auto [d, cur] = pq.top(); pq.pop();
            if(dist[cur] != d) continue;
            for(auto [nxt, w] : G[cur]) {
                if(dist[nxt] > dist[cur] + w) {
                    dist[nxt] = dist[cur] + w;
                    pq.emplace(dist[nxt], nxt);
                }
            }
        }
        return dist;
    }
};
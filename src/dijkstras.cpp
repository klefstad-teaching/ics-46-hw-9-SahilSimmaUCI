#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> distance(n, INF);
    previous.assign(n, -1);
    vector<bool> visited(n, false);

    using Pair = pair<int,int>;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        for (auto& edge : G[u]) {
            int v = edge.dst;
            int w = edge.weight;
            if (!visited[v] && currentDist + w < distance[v]) {
                distance[v] = currentDist + w;
                previous[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous,  int destination) {
    vector<int> ret;
    for (int cur = destination; cur != -1; cur = previous[cur]) {
        ret.push_back(cur);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void print_path(const vector<int>& v, int total) {
    if (v.empty()) {
        cout << "No path found." << endl;
        return;
    }
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\nTotal cost: " << total << endl;
}
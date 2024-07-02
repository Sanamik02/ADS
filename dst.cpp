#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int weight) {
    adj[u].push_back({v, weight});

}

void Dijkstra(vector<vector<pair<int, int>>>& adj, int start, vector<int>& dist) {
    int V = adj.size(); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  

    dist[start] = 0;  
    pq.push({0, start});  

    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();

        if (current_dist > dist[u])
            continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}


int main() {
    int V = 5;  
    vector<vector<pair<int, int>>> adj(V);  

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 1, 3, 1);
    addEdge(adj, 2, 1, 2);
    addEdge(adj, 2, 3, 5);
    addEdge(adj, 3, 4, 3);

    int start = 0; 

    vector<int> dist(V, numeric_limits<int>::max());

    Dijkstra(adj, start, dist);

    cout << "Кратчайшие расстояния от вершины " << start << ":\n";
    for (int i = 0; i < V; ++i)
        cout << "Вершина " << i << ": " << dist[i] << endl;

    return 0;
}
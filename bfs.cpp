#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;


void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
   
}

void BFS(vector<vector<int>>& adj, int start) {
    int V = adj.size();  
    vector<bool> visited(V, false); 
    queue<int> q;  

    visited[start] = true;  
    q.push(start); 

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";  

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;  
                q.push(v); 
            }
        }
    }
}

int main() {
    int V = 6;  
    vector<vector<int>> adj(V);  

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);

    cout << "BFS начиная с вершины 0: ";
    BFS(adj, 0);

    return 0;
}
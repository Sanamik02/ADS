#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;


void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
  
}


void DFSUtil(vector<vector<int>>& adj, int v, vector<bool>& visited) {
    visited[v] = true; 
    cout << v << " "; 

    for (int u : adj[v]) {
        if (!visited[u]) {
            DFSUtil(adj, u, visited);
        }
    }
}


void DFS(vector<vector<int>>& adj, int start) {
    int V = adj.size();  
    vector<bool> visited(V, false); 

    DFSUtil(adj, start, visited);  
}


int main() {
    int V = 6;  
    vector<vector<int>> adj(V); 

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);

    cout << "DFS начиная с вершины 0: ";
    DFS(adj, 0);

    return 0;
}
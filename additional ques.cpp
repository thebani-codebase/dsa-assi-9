/*
Name: Bani
Roll No: 102403190
Additional Question 1: Count Connected Components in Graph
*/

#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    
    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

int countConnectedComponents(int V, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(V);
    
    // Build adjacency list
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> visited(V, false);
    int components = 0;
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, adj, visited);
            components++;
        }
    }
    
    return components;
}

int main() {
    int V = 5;
    vector<pair<int, int>> edges;
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({3, 4});
    
    cout << "Number of Connected Components: " << countConnectedComponents(V, edges) << endl;
    
    return 0;
}

/*
Name: Bani
Roll No: 102403190
Question 4: Dijkstra's Shortest Path Algorithm
*/

#include <iostream>
#include <vector>
#include limits>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    
public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V, vector<int>(V, 0));
    }
    
    void addEdge(int u, int v, int weight) {
        adj[u][v] = weight;
        adj[v][u] = weight;
    }
    
    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);
        
        dist[src] = 0;
        
        for (int count = 0; count < V - 1; count++) {
            int minDist = INT_MAX;
            int u = -1;
            
            // Find vertex with minimum distance
            for (int v = 0; v < V; v++) {
                if (!visited[v] && dist[v] < minDist) {
                    minDist = dist[v];
                    u = v;
                }
            }
            
            visited[u] = true;
            
            // Update distances of adjacent vertices
            for (int v = 0; v < V; v++) {
                if (!visited[v] && adj[u][v] && dist[u] != INT_MAX &&
                    dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
        
        cout << "Shortest distances from vertex " << src << ":" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            if (dist[i] == INT_MAX) {
                cout << "INF" << endl;
            } else {
                cout << dist[i] << endl;
            }
        }
    }
};

int main() {
    Graph g(5);
    
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);
    
    g.dijkstra(0);
    
    return 0;
}

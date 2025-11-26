/*
Name: Bani
Roll No: 102403190
Question 3b: Minimum Spanning Tree - Prim's Algorithm
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
    
    void primMST() {
        vector<int> parent(V);
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        
        key[0] = 0;
        parent[0] = -1;
        
        for (int count = 0; count < V - 1; count++) {
            int minKey = INT_MAX;
            int u = -1;
            
            // Find minimum key vertex not in MST
            for (int v = 0; v < V; v++) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }
            
            inMST[u] = true;
            
            // Update key values of adjacent vertices
            for (int v = 0; v < V; v++) {
                if (adj[u][v] && !inMST[v] && adj[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adj[u][v];
                }
            }
        }
        
        cout << "Prim's MST Edges:" << endl;
        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " -- " << i << " (Weight: " << adj[i][parent[i]] << ")" << endl;
            totalWeight += adj[i][parent[i]];
        }
        cout << "Total MST Weight: " << totalWeight << endl;
    }
};

int main() {
    Graph g(5);
    
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    
    g.primMST();
    
    return 0;
}

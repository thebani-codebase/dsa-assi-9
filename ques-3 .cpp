/*
Name: Bani
Roll No: 102403190
Question 3a: Minimum Spanning Tree - Kruskal's Algorithm
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DSU {
    vector<int> parent, rank;
    
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    
    DSU dsu(V);
    vector<Edge> mst;
    int totalWeight = 0;
    
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        
        if (dsu.find(u) != dsu.find(v)) {
            mst.push_back(edges[i]);
            totalWeight += weight;
            dsu.unite(u, v);
        }
    }
    
    cout << "Kruskal's MST Edges:" << endl;
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].u << " -- " << mst[i].v << " (Weight: " << mst[i].weight << ")" << endl;
    }
    cout << "Total MST Weight: " << totalWeight << endl;
}

int main() {
    int V = 4;
    vector<Edge> edges;
    
    edges.push_back({0, 1, 10});
    edges.push_back({0, 2, 6});
    edges.push_back({0, 3, 5});
    edges.push_back({1, 3, 15});
    edges.push_back({2, 3, 4});
    
    kruskalMST(V, edges);
    
    return 0;
}

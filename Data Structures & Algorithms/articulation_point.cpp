#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    list<int> *adj;

    void APUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, int& time, int parent, vector<bool>& isAP) {
        int children = 0;
        visited[u] = true;
        disc[u] = low[u] = ++time;

        for (auto v : adj[u]) {
            if (v == parent)
                continue;

            if (visited[v]) {
                // Back-edge
                low[u] = min(low[u], disc[v]);
            } else {
                children++;
                APUtil(v, visited, disc, low, time, u, isAP);

                // Check if the subtree rooted with v has a connection to
                // one of the ancestors of u
                low[u] = min(low[u], low[v]);

                // u is an articulation point in following cases:

                // (1) u is root of DFS tree and has two or more children.
                if (parent != -1 && low[v] >= disc[u])
                    isAP[u] = true;
            }
        }
        
        // (2) If u is root of DFS tree and has two or more children.
        if (parent == -1 && children > 1)
            isAP[u] = true;
    }

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); // Undirected graph
    }

    void findAPs() {
        vector<int> disc(V);
        vector<int> low(V);
        vector<bool> visited(V, false);
        vector<bool> isAP(V, false);
        int time = 0;
        int parent = -1;

        // Call the recursive helper function to find articulation points
        // in DFS tree traversal for every vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                APUtil(i, visited, disc, low, time, parent, isAP);
        }

        cout << "Articulation points in the graph are: ";
        bool found = false;
        for (int i = 0; i < V; i++) {
            if (isAP[i]) {
                cout << i << " ";
                found = true;
            }
        }
        if (!found) cout << "None";
        cout << endl;
    }
};

int main() {
    // Create graphs and find articulation points
    cout << "\nArticulation points in first graph: \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    // Graph:
    // 1--0--3--4
    // | /
    // 2 
    // APs should be 0 and 3.
    // 0 connects {1,2} to {3,4}
    // 3 connects {4} to rest.
    g1.findAPs();

    cout << "\nArticulation points in second graph: \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    // 0-1-2-3
    // APs: 1, 2
    g2.findAPs();

    cout << "\nArticulation points in third graph: \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    // APs should be 1.
    g3.findAPs();

    return 0;
}

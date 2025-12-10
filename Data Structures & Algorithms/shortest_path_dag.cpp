#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <list>

using namespace std;

class Graph {
public:
    int V;
    // Adjacency list: node -> list of pairs (neighbor, weight)
    vector<list<pair<int, int>>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
    }

    void dfs(int node, vector<bool> &visited, stack<int> &topo) {
        visited[node] = true;

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor.first]) {
                dfs(neighbor.first, visited, topo);
            }
        }
        topo.push(node);
    }

    void shortestPath(int src) {
        vector<int> dist(V, INT_MAX);
        stack<int> topo;
        vector<bool> visited(V, false);

        // Step 1: Topological Sort
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, topo);
            }
        }

        // Step 2: Initialize distance to source
        dist[src] = 0;

        // Step 3: Process nodes in topological order
        while (!topo.empty()) {
            int top = topo.top();
            topo.pop();

            // If the node has been reached
            if (dist[top] != INT_MAX) {
                for (auto i : adj[top]) {
                    int neighbor = i.first;
                    int weight = i.second;

                    if (dist[top] + weight < dist[neighbor]) {
                        dist[neighbor] = dist[top] + weight;
                    }
                }
            }
        }

        // Print results
        cout << "Shortest distances from source " << src << ":" << endl;
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    
    int src = 1;
    g.shortestPath(src);

    return 0;
}

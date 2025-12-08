#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    // Add an edge to the graph
    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed

        // Create an edge from u to v
        adj[u].push_back(v);

        // If undirected, create an edge from v to u
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    // Print the adjacency list
    void printGraph() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    // BFS Traversal
    void bfs(int startNode) {
        unordered_map<int, bool> visited;
        queue<int> q;

        q.push(startNode);
        visited[startNode] = true;

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int front = q.front();
            q.pop();

            cout << front << " ";

            for (auto neighbor : adj[front]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout << endl;
    }

    // DFS Helper Function
    void dfsUtil(int node, unordered_map<int, bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    // DFS Traversal
    void dfs(int startNode) {
        unordered_map<int, bool> visited;
        cout << "DFS Traversal: ";
        dfsUtil(startNode, visited);
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;

    Graph g;

    cout << "Enter edges (u v): " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Creating an undirected graph
        g.addEdge(u, v, 0);
    }

    // Printing the graph
    cout << "\nAdjacency List:" << endl;
    g.printGraph();

    cout << "\nEnter Start Node for BFS/DFS: ";
    int startNode;
    cin >> startNode;

    g.bfs(startNode);
    g.dfs(startNode);

    return 0;
}

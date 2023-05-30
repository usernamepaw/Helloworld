#include <iostream>
#include <vector>
#include <stack>
 using namespace std;
 // Function to perform DFS traversal of a graph
void DFS(vector<vector<int>>& graph, int start_node) {
    // Initialize visited array with false
    vector<bool> visited(graph.size(), false);
    // Create a stack for DFS traversal
    stack<int> s;
    // Push the starting node onto the stack
    s.push(start_node);
    // Traverse the graph using DFS
    while (!s.empty()) {
        // Pop a node from the stack and mark it as visited
        int node = s.top();
        s.pop();
        visited[node] = true;
        cout << node << " ";
        // Traverse all the neighbours of the current node
        for (auto neighbour : graph[node]) {
            // Push the unvisited neighbours onto the stack
            if (!visited[neighbour]) {
                s.push(neighbour);
            }
        }
    }
}
 int main() {
    // Example graph represented using adjacency list
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 5, 6},
                                 {1}, {1}, {2}, {2}};
    int start_node = 0;  // Starting node for DFS traversal
    // Call DFS on the starting node
    DFS(graph, start_node);
    return 0;
}
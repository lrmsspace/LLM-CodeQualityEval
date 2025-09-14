/**https://leetcode.com/problems/shortest-cycle-in-a-graph/ */
//There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
//Return the length of the shortest cycle in the graph. If no cycle exists, return -1.
//A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.
// 
//Example 1:
//Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
//Output: 3
//Explanation: The cycle with the smallest length is : 0 -> 1 -> 2 -> 0 
//Example 2:
//Input: n = 4, edges = [[0,1],[0,2]]
//Output: -1
//Explanation: There are no cycles in this graph.
// 
//Constraints:
//	2 <= n <= 1000
//	1 <= edges.length <= 1000
//	edges[i].length == 2
//	0 <= ui, vi < n
//	ui != vi
//	There are no repeated edges.
int findShortestCycle(int n, int** edges, int edgesSize, int* edgesColSize) {
    // Initialize an adjacency list to store the graph
    vector<vector<int>> graph(n);
    for (int i = 0; i < edgesSize; i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    // Initialize a visited array to keep track of visited vertices
    vector<bool> visited(n, false);
    
    // Initialize a parent array to store the parent vertex of each vertex
    vector<int> parent(n, -1);
    
    // Initialize a result array to store the shortest cycle
    vector<int> result;
    
    // Perform depth-first search to find the shortest cycle
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, visited, parent, result, i);
            if (!result.empty()) {
                break;
            }
        }
    }
    
    // Return the length of the shortest cycle or -1 if no cycle exists
    if (result.empty()) {
        return -1;
    } else {
        return result.size();
    }
    
    // Helper function for depth-first search
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& parent, vector<int>& result, int current) {
        visited[current] = true;
        result.push_back(current);
        
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                parent[neighbor] = current;
                dfs(graph, visited, parent, result, neighbor);
            } else if (neighbor!= parent[current]) {
                // Found a cycle
                int cycleStart = neighbor;
                while (cycleStart!= current) {
                    result.push_back(cycleStart);
                    cycleStart = parent[cycleStart];
                }
                result.push_back(current);
                reverse(result.begin(), result.end());
                return;
            }
        }
        
        result.pop_back();
    }
    
}
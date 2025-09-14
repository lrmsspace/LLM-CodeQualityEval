/**https://leetcode.com/problems/shortest-path-with-alternating-colors/ */
//You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.
//You are given two arrays redEdges and blueEdges where:
//	redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
//	blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
//Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
// 
//Example 1:
//Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
//Output: [0,1,-1]
//Example 2:
//Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
//Output: [0,1,-1]
// 
//Constraints:
//	1 <= n <= 100
//	0 <= redEdges.length, blueEdges.length <= 400
//	redEdges[i].length == blueEdges[j].length == 2
//	0 <= ai, bi, uj, vj < n
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> graph(n, vector<int>(2));
        for (const auto& edge : redEdges) {
            graph[edge[0]][0]++;
            graph[edge[1]][1]++;
        }
        for (const auto& edge : blueEdges) {
            graph[edge[0]][0]++;
            graph[edge[1]][1]++;
        }
        
        queue<pair<int, int>> q;
        q.push({0, 0}); // Start from node 0, with 0 red edges and 0 blue edges
        
        vector<int> dist(n, -1);
        dist[0] = 0;
        
        while (!q.empty()) {
            int node = q.front().first;
            int edges = q.front().second;
            q.pop();
            
            if (edges == n - 1) {
                break;
            }
            
            for (int i = 0; i < 2; i++) {
                for (int neighbor = 0; neighbor < n; neighbor++) {
                    if (graph[neighbor][i] > 0 && (dist[neighbor] == -1 || dist[node] + 1 < dist[neighbor])) {
                        dist[neighbor] = dist[node] + 1;
                        q.push({neighbor, edges + (i == 0? 1 : 0)});
                        graph[neighbor][i]--;
                    }
                }
            }
        }
        
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++) {
            result[i] = dist[i] == -1? -1 : dist[i] * 2;
        }
        return result;
        
    }
};
/**https://leetcode.com/problems/shortest-path-visiting-all-nodes/ */
//You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.
//Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
// 
//Example 1:
//Input: graph = [[1,2,3],[0],[0],[0]]
//Output: 4
//Explanation: One possible path is [1,0,2,0,3]
//Example 2:
//Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
//Output: 4
//Explanation: One possible path is [0,1,4,2,3]
// 
//Constraints:
//	n == graph.length
//	1 <= n <= 12
//	0 <= graph[i].length < n
//	graph[i] does not contain i.
//	If graph[a] contains b, then graph[b] contains a.
//	The input graph is always connected.
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allVisited = (1 << n) - 1;
        vector<vector<bool>> visited(n, vector<bool>(allVisited + 1, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [node, mask] = q.front();
                q.pop();
                if (mask == allVisited) {
                    return steps;
                }
                for (int neighbor : graph[node]) {
                    int newMask = mask | (1 << neighbor);
                    if (!visited[neighbor][newMask]) {
                        q.push({neighbor, newMask});
                        visited[neighbor][newMask] = true;
                    }
                }
            }
            steps++;
        }
        return -1;      
    }
};
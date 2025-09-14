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
int shortestPathLength(int** graph, int graphSize, int* graphColSize) {
    int n = graphSize;
    int dp[1 << n][n];
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }
    for (int mask = 1; mask < 1 << n; mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;
            for (int j : graph[i]) {
                if (mask & (1 << j)) {
                    dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + 1);
                }
            }
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        res = min(res, dp[(1 << n) - 1][i]);
    }
    return res;
}
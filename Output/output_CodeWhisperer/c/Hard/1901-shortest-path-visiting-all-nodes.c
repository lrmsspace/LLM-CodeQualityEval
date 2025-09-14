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

    int dp[n][1 << n];

    memset(dp, -1, sizeof(dp));

    int queue[n * (1 << n)];

    int head = 0, tail = 0;

    for (int i = 0; i < n; i++) {

        queue[tail++] = i * (1 << n) + (1 << i);

        dp[i][1 << i] = 0;

    }

    int ans = 0;


    while (head < tail) {

        int cur = queue[head++];

        int u = cur / (1 << n), mask = cur % (1 << n);

        for (int v : graph[u]) {

            int new_mask = mask | (1 << v);

            if (dp[v][new_mask] == -1) {

                dp[v][new_mask] = dp[u][mask] + 1;

                if (new_mask == (1 << n) - 1) {

                    ans = dp[v][new_mask];

                    return ans;

                }

                queue[tail++] = v * (1 << n) + new_mask;

            }

        }

    }
    return ans;
    
}
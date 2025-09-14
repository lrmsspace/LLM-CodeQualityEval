/**https://leetcode.com/problems/largest-color-value-in-a-directed-graph/ */
//There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1._x000D_
//_x000D_
//You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj._x000D_
//_x000D_
//A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path._x000D_
//_x000D_
//Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]_x000D_
//Output: 3_x000D_
//Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image)._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: colors = "a", edges = [[0,0]]_x000D_
//Output: -1_x000D_
//Explanation: There is a cycle from 0 to 0._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	n == colors.length_x000D_
//	m == edges.length_x000D_
//	1 <= n <= 105_x000D_
//	0 <= m <= 105_x000D_
//	colors consists of lowercase English letters._x000D_
//	0 <= aj, bj < n_x000D_
int largestPathValue(char * colors, int** edges, int edgesSize, int* edgesColSize){
    int n = strlen(colors);
    int indegree[n] = {0};
    int graph[n][26] = {0};
    int ans[n][26] = {0};
    int q[n] = {0}, h = 0, t = -1;
    int i, j, k, u, v, c, m, x, y, z;
    for (i = 0; i < edgesSize; i++) {
        u= edges[i][0];
    }
    for (i = 0; i < edgesSize; i++) {
        v = edges[i][1];
        indegree[v]++;
    }
    for (i = 0; i < n; i++) {
        if (!indegree[i]) {
            q[++t] = i;
        }
    }
    while (h <= t) {
        u = q[h++];
        c = colors[u] - 'a';
        for (i = 0; i < 26; i++) {
            ans[u][i] += graph[u][i];
        }
        for (i = 0; i < edgesSize; i++) {
            v = edges[i][0];
            if (u == v) {
                continue;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            x = ans[i][j];
            for (k = i + 1; k < n; k++) {
                y = ans[k][j];
                z = x + y;
                x = z > x ? z : x;
            }
            m = x > m ? x: m;
        }
    }
    return m;
}
/**https://leetcode.com/problems/maximum-star-sum-of-a-graph/ */
//There is an undirected graph consisting of n nodes numbered from 0 to n - 1. You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node.
//You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
//A star graph is a subgraph of the given graph having a center node containing 0 or more neighbors. In other words, it is a subset of edges of the given graph such that there exists a common node for all edges.
//The image below shows star graphs with 3 and 4 neighbors respectively, centered at the blue node.
//The star sum is the sum of the values of all the nodes present in the star graph.
//Given an integer k, return the maximum star sum of a star graph containing at most k edges.
// 
//Example 1:
//Input: vals = [1,2,3,4,10,-10,-20], edges = [[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]], k = 2
//Output: 16
//Explanation: The above diagram represents the input graph.
//The star graph with the maximum star sum is denoted by blue. It is centered at 3 and includes its neighbors 1 and 4.
//It can be shown it is not possible to get a star graph with a sum greater than 16.
//Example 2:
//Input: vals = [-5], edges = [], k = 0
//Output: -5
//Explanation: There is only one possible star graph, which is node 0 itself.
//Hence, we return -5.
// 
//Constraints:
//	n == vals.length
//	1 <= n <= 105
//	-104 <= vals[i] <= 104
//	0 <= edges.length <= min(n * (n - 1) / 2, 105)
//	edges[i].length == 2
//	0 <= ai, bi <= n - 1
//	ai != bi
//	0 <= k <= n - 1
int maxStarSum(int* vals, int valsSize, int** edges, int edgesSize, int* edgesColSize, int k) {
    int n = valsSize;
    int *degree = (int *)malloc(sizeof(int) * n);
    int *sum = (int *)malloc(sizeof(int) * n);
    int *visited = (int *)malloc(sizeof(int) * n);
    int i, j, res = 0;
    for (i = 0; i < n; i++) {
        degree[i] = 0;
        sum[i] = vals[i];
        visited[i] = 0;
    }
    for (i = 0; i < edgesSize; i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }
    for (i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        if (degree[u] > degree[v] || (degree[u] == degree[v] && u > v)) {
            int tmp = u;
            u = v;
            v = tmp;
        }
        sum[v] += sum[u];
    }
    for (i = 0; i < n; i++) {
        if (degree[i] == 1) {
            visited[i] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (degree[i] == 1 && !visited[i]) {
            int u = i;
            int v = -1;
            while (degree[u] == 1) {
                visited[u] = 1;
                for (j = 0; j < edgesSize; j++) {
                    if (edges[j][0] == u && !visited[edges[j][1]]) {
                        v = edges[j][1];
                        break;
                    }
                    if (edges[j][1] == u && !visited[edges[j][0]]) {
                        v = edges[j][0];
                        break;
                    }
                }
                if (v == -1) {
                    break;
                }
                degree[v]--;
                sum[v] += sum[u];
                u = v;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (degree[i] == 1) {
            res = fmax(res, sum[i]);
        }
    }
    return res;    
}
/**https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/ */
//There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.
//A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.
//The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.
//Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
//Output: 3
//Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
//1) 1 --> 2 --> 5
//2) 1 --> 2 --> 3 --> 5
//3) 1 --> 3 --> 5
//Example 2:
//Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
//Output: 1
//Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The only restricted path is 1 --> 3 --> 7.
// 
//Constraints:
//	1 <= n <= 2 * 104
//	n - 1 <= edges.length <= 4 * 104
//	edges[i].length == 3
//	1 <= ui, vi <= n
//	ui != vi
//	1 <= weighti <= 105
//	There is at most one edge between any two nodes.
//	There is at least one path between any two nodes.
int countRestrictedPaths(int n, int** edges, int edgesSize, int* edgesColSize){
    int i, j, k, l, m, u, v, w, cnt = 0;
    int *dis = (int *)malloc(sizeof(int) * (n + 1));
    memset(dis, 0, sizeof(int) * (n + 1));
    int *vis = (int *)malloc(sizeof(int) * (n + 1));
    memset(vis, 0, sizeof(int) * (n + 1));
    int *cnt_path = (int *)malloc(sizeof(int)* (n + 1));
    memset(cnt_path, 0, sizeof(int) * (n + 1));
    for (i = 0; i < n; i++) {
        cnt_path[i + 1] = 1;
    }
    for (i = 0; i < edgesSize; i++) {
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];
        dis[v] = dis[u] + w;
    }
    for (i = 0; i < edgesSize; i++) {
        u = edges[i][1];
        v = edges[i][0];
        w = edges[i][2];
        dis[u] = dis[v] + w;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            if (dis[i] > dis[j]) {
                cnt_path[i] += cnt_path[j];
                cnt_path[i] %= 1000000007;
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            if (dis[i] < dis[j]) {
                cnt_path[j] = cnt_path[j] - cnt_path[i];
                cnt_path[j] %= 1000000007;
           }
        }
    }
    return cnt_path[n];
}
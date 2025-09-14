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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestAlternatingPaths(int n, int** redEdges, int redEdgesSize, int* redEdgesColSize, int** blueEdges, int blueEdgesSize, int* blueEdgesColSize, int* returnSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100] = {0};
    int b[100] = {0};
    int c[100] = {0};
    int d[100] = {0};
    int e[100] = {0};
    int f[100] = {0};
    int g[100] = {0};
    int h[100] = {0};
    int ans = 0;
    int *ret = (int *)malloc(sizeof(int) * 100);
    int head = 0;
    int tail = 0;
    int queue[100];
    for(i = 0; i < 100; i++) {
        queue[tail] = i;
        tail++;
    }
    for(i = 0; i < redEdgesSize; i++) {
        a[i] = redEdges[i][0];
        b[i] = redEdges[i][1];
    }
    for(i = 0; i < blueEdgesSize; i++) {
        c[i] = blueEdges[i][0];
        d[i] = blueEdges[i][1];
    }
    for(i = 0; i < n; i++) {
        ret[i] = -1;
    }
    ret[0] = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < redEdgesSize; j++) {
            if(ret[a[j]] != -1 && (ret[b[j]] == -1 || ret[b[j]] > ret[a[j]] + 1)) {
                ret[b[j]] = ret[a[j]] + 1;
            }
        }
        for(j = 0; j < blueEdgesSize; j++) {
            if(ret[c[j]] != -1 && (ret[d[j]] == -1 || ret[d[j]] > ret[c[j]] + 1)) {
                ret[d[j]] = ret[c[j]] + 1;
            }
        }
    }
    *returnSize = n;
    return ret;
}
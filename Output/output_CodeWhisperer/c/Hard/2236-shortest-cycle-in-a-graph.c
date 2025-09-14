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
    int minCycle = INT_MAX;
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        for (int j = 0; j < n; j++) {
            dist[j] = INT_MAX;
        }
        dist[u] = 0;
        int cycleLength = INT_MAX;
        while (v != -1) {
            if (dist[v] < INT_MAX) {
                cycleLength = dist[u] + dist[v] + 1;
                break;
            }
            dist[v] = dist[u] + 1;
            u = v;
            v = -1;
            for (int j = 0; j < edgesSize; j++) {
                if (edges[j][0] == u) {
                    v = edges[j][1];
                    break;
                }
                if (edges[j][1] == u) {
                    v = edges[j][0];
                    break;
                }
            }
        }
        if (cycleLength < minCycle) {
            minCycle = cycleLength;
        }
    }
    if (minCycle == INT_MAX) {
        return -1;
    }
    return minCycle;
}
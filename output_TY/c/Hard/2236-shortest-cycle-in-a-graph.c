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
int findShortestCycle(int n, int** edges, int edgesSize, int* edgesColSize){
    int* visited = (int*)calloc(n, sizeof(int));
    int* dist = (int*)calloc(n, sizeof(int));
    int* parent = (int*)calloc(n, sizeof(int));
    int min_cycle = INT_MAX;
    int i, j, k, u, v, len;
    for (i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        memset(visited, 0,n * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        memset(visited, 0,n * sizeof(int));
        memset(dist, 0,n * sizeof(int));
        memset(parent, -1,n * sizeof(int));
        visited[i] = 1;
        dist[i] = 0;
        parent[i] = i;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < edgesSize; j++) {
            u = edges[j][0];
            v = edges[j][1];
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < edgesSize; j++) {
            u = edges[j][0];
            v = edges[j][1];
            if (dist[u] + 1 == dist[v]) {
                len = 0;
                k = v;
                while (k != u) {
                    len++;
                    k =parent[k];
                }
            }
        }
    }
    return min_cycle == INT_MAX ? -1 : min_cycle;
}
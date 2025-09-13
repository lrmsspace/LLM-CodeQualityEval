/**https://leetcode.com/problems/find-if-path-exists-in-graph/ */
//There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
//You want to determine if there is a valid path that exists from vertex source to vertex destination.
//Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
// 
//Example 1:
//Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
//Output: true
//Explanation: There are two paths from vertex 0 to vertex 2:
//- 0 → 1 → 2
//- 0 → 2
//Example 2:
//Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
//Output: false
//Explanation: There is no path from vertex 0 to vertex 5.
// 
//Constraints:
//	1 <= n <= 2 * 105
//	0 <= edges.length <= 2 * 105
//	edges[i].length == 2
//	0 <= ui, vi <= n - 1
//	ui != vi
//	0 <= source, destination <= n - 1
//	There are no duplicate edges.
//	There are no self edges.
bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    bool *visited = (bool *)malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    struct Stack {
        int size;
        int *data;
    };

    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = 0;
    stack->data = (int *)malloc(n * sizeof(int));

    stack->data[stack->size++] = source;
    visited[source] = true;

    while (stack->size > 0) {
        int current = stack->data[--stack->size];
        if (current == destination) {
            return true;
        }

        for (int i = 0; i < edgesSize; i++) {
            if (edges[i][0] == current && !visited[edges[i][1]]) {
                stack->data[stack->size++] = edges[i][1];
                visited[edges[i][1]] = true;
            } else if (edges[i][1] == current && !visited[edges[i][0]]) {
                stack->data[stack->size++] = edges[i][0];
                visited[edges[i][0]] = true;
            }
        }
    }

    free(visited);
    free(stack->data);
    free(stack);

    return false;
}
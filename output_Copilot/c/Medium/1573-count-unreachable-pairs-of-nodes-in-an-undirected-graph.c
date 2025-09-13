/**https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/ */
//You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
//Return the number of pairs of different nodes that are unreachable from each other.
// 
//Example 1:
//Input: n = 3, edges = [[0,1],[0,2],[1,2]]
//Output: 0
//Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
//Example 2:
//Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
//Output: 14
//Explanation: There are 14 pairs of nodes that are unreachable from each other:
//[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
//Therefore, we return 14.
// 
//Constraints:
//	1 <= n <= 105
//	0 <= edges.length <= 2 * 105
//	edges[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	There are no repeated edges.
long long countPairs(int n, int** edges, int edgesSize, int* edgesColSize) {
    int *graph = (int *)malloc(sizeof(int) * n * n);
    memset(graph, 0, sizeof(int) * n * n);
    for (int i = 0; i < edgesSize; i++) {
        graph[edges[i][0] * n + edges[i][1]] = 1;
        graph[edges[i][1] * n + edges[i][0]] = 1;
    }
    int *visited = (int *)malloc(sizeof(int) * n);
    memset(visited, 0, sizeof(int) * n);
    int *unreachable = (int *)malloc(sizeof(int) * n);
    memset(unreachable, 0, sizeof(int) * n);
    int *stack = (int *)malloc(sizeof(int) * n);
    int stackSize = 0;
    stack[stackSize++] = 0;
    visited[0] = 1;
    while (stackSize) {
        int node = stack[--stackSize];
        for (int i = 0; i < n; i++) {
            if (graph[node * n + i] && !visited[i]) {
                stack[stackSize++] = i;
                visited[i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        unreachable[i] = !visited[i];
    }
    long long result = 0;
    for (int i = 0; i < n; i++) {
        if (unreachable[i]) {
            result += n - 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (unreachable[i]) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (unreachable[j]) {
                continue;
            }
            if (!graph[i * n + j]) {
                result++;
            }
        }
    }
    return result;    
}
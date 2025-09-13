/**https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/ */
//Alice and Bob have an undirected graph of n nodes and three types of edges:
//	Type 1: Can be traversed by Alice only.
//	Type 2: Can be traversed by Bob only.
//	Type 3: Can be traversed by both Alice and Bob.
//Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.
//Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.
// 
//Example 1:
//Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
//Output: 2
//Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
//Example 2:
//Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
//Output: 0
//Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
//Example 3:
//Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
//Output: -1
//Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
// 
// 
//Constraints:
//	1 <= n <= 105
//	1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
//	edges[i].length == 3
//	1 <= typei <= 3
//	1 <= ui < vi <= n
//	All tuples (typei, ui, vi) are distinct.
int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize){
    int *parentA = (int *)malloc(sizeof(int) * n);
    int *parentB = (int *)malloc(sizeof(int) * n);
    int *rankA = (int *)malloc(sizeof(int) * n);
    int *rankB = (int *)malloc(sizeof(int) * n);
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    for (i = 0; i < n; i++) {
        parentA[i] = i;
        parentB[i] = i;
        rankA[i] = 0;
        rankB[i] = 0;
    }
    for (i = 0; i < edgesSize; i++) {
        if (edges[i][0] == 3) {
            j = find(parentA, edges[i][1] - 1);
            k = find(parentB, edges[i][2] - 1);
            if (j != k) {
                if (rankA[j] > rankB[k]) {
                    parentB[k] = j;
                }
            }
        }
    }
    for (i = 0; i < edgesSize; i++) {
        if (edges[i][0] == 3) {
            j = find(parentA, edges[i][1] - 1);
            k = find(parentB, edges[i][2] - 1);
            if (j == k) {
                return -1;
            }
        }
    }
    for (i = 0; i < edgesSize; i++) {
        if (edges[i][0] == 1) {
            j = find(parentA, edges[i][1] - 1);
            k = find(parentA, edges[i][2] - 1);
            if (j != k) {
                if (rankA[j] > rankA[k]) {
                    parentA[k] = j;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        j = find(parentA, i);
        if (j == i) {
            break;
        }
    }
    if (i == n) {
        return -1;
    }
    for (i = 0; i < edgesSize; i++) {
        if (edges[i][0] == 2) {
            j = find(parentB, edges[i][1] - 1);
            k = find(parentB, edges[i][2] - 1);
            if (j != k) {
                if (rankB[j] > rankB[k]) {
                    parentB[k] = j;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        j = find(parentB, i);
        if (j == i) {
            break;
        }
    }
    if (i == n) {
        return -1;
    }
    return edgesSize - (n - 1);
}
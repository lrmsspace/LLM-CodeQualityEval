/**https://leetcode.com/problems/redundant-connection-ii/ */
//In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.
//The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
//The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.
//Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.
// 
//Example 1:
//Input: edges = [[1,2],[1,3],[2,3]]
//Output: [2,3]
//Example 2:
//Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
//Output: [4,1]
// 
//Constraints:
//	n == edges.length
//	3 <= n <= 1000
//	edges[i].length == 2
//	1 <= ui, vi <= n
//	ui != vi
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int *parent = (int *)malloc(sizeof(int) * (edgesSize + 1));
    int *candidate1 = NULL;
    int *candidate2 = NULL;
    int *result = NULL;
    *returnSize = 2;
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < edgesSize; i++) {
        if (parent[edges[i][1]] != edges[i][1]) {
            candidate1 = (int *)malloc(sizeof(int) * 2);
            candidate1[0] = parent[edges[i][1]];
            candidate1[1] = edges[i][1];
            candidate2 = (int *)malloc(sizeof(int) * 2);
            candidate2[0] = edges[i][0];
            candidate2[1] = edges[i][1];
            edges[i][1] = 0;
        } else {
            parent[edges[i][1]] = edges[i][0];
        }
    }
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][1] == 0) {
            continue;
        }
        if (parent[edges[i][1]] == edges[i][1]) {
            parent[edges[i][1]] = edges[i][0];
        } else {
            result = (int *)malloc(sizeof(int) * 2);
            result[0] = candidate1[0];
            result[1] = candidate1[1];
            return result;
        }
    }
    return candidate2;    
}
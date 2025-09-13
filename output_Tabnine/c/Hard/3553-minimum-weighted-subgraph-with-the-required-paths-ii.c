/*
 You are given an undirected weighted tree with n nodes, numbered from 0 to n - 1. It is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi, wi] indicates that there is an edge between nodes ui and vi with weight wi.​
 Additionally, you are given a 2D integer array queries, where queries[j] = [src1j, src2j, destj].
 Return an array answer of length equal to queries.length, where answer[j] is the minimum total weight of a subtree such that it is possible to reach destj from both src1j and src2j using edges in this subtree.
 A subtree here is any connected subset of nodes and edges of the original tree forming a valid tree.
 Example 1:
 Input: edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], queries = [[2,3,4],[0,2,5]]
 Output: [12,11]
 Explanation:
 The blue edges represent one of the subtrees that yield the optimal answer.
 answer[0]: The total weight of the selected subtree that ensures a path from src1 = 2 and src2 = 3 to dest = 4 is 3 + 5 + 4 = 12.
 answer[1]: The total weight of the selected subtree that ensures a path from src1 = 0 and src2 = 2 to dest = 5 is 2 + 3 + 6 = 11.
 Example 2:
 Input: edges = [[1,0,8],[0,2,7]], queries = [[0,1,2]]
 Output: [15]
 Explanation:
 answer[0]: The total weight of the selected subtree that ensures a path from src1 = 0 and src2 = 1 to dest = 2 is 8 + 7 = 15.
 Constraints:
 3 <= n <= 105
 edges.length == n - 1
 edges[i].length == 3
 0 <= ui, vi < n
 1 <= wi <= 104
 1 <= queries.length <= 105
 queries[j].length == 3
 0 <= src1j, src2j, destj < n
 src1j, src2j, and destj are pairwise distinct.
 The input is generated such that edges represents a valid tree.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minimumWeight(int** edges, int edgesSize, int* edgesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {

    int* result = malloc(queriesSize * sizeof(int));    
    *returnSize = queriesSize;


    // Build the adjacency list
    int** adjList = (int**)malloc(edgesSize * sizeof(int*));
    for (int i = 0; i < edgesSize; i++) {
        adjList[i] = (int*)malloc(3 * sizeof(int));
        adjList[i][0] = edges[i][1];
        adjList[i][1] = edges[i][2];
        adjList[i][2] = i;
    }       
    // Perform depth-first search to find the minimum total weight
    for (int i = 0; i < edgesSize; i++) {
        int* visited = (int*)malloc(edgesSize * sizeof(int));
        dfs(adjList, visited, edges[i][0], 0, edges[i][2], 0);
        free(visited);
    }
    
    // Perform the queries
    for (int i = 0; i < queriesSize; i++) {
        int src1 = queries[i][0];
        int src2 = queries[i][1];
        int dest = queries[i][2];
        result[i] = minWeightHelper(adjList, queries[i][0], queries[i][1], dest);
    }
    
    // Free the adjacency list
    for (int i = 0; i < edgesSize; i++) {
        free(adjList[i]);
    }
    free(adjList);
    
    return result;
    
}
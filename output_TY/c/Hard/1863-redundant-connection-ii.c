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
int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int n = 0;
    for (int i = 0; i < edgesSize; i++) {
        n = n > edges[i][0] ? n : edges[i][0];
        n = n > edges[i][1] ? n : edges[i][1];
    }
    int* parent = (int*)malloc(sizeof(int) * (n + 1));
    memset(parent, 0, sizeof(int) * (n + 1));
    int* vis = (int*)malloc(sizeof(int) * (n + 1));
    memset(vis, 0, sizeof(int) * (n + 1));
    for (int i = 0; i < edgesSize; i++) {
        if (vis[edges[i][1]]) {
            int* ans = (int*)malloc(sizeof(int) * 2);
            ans[0] = edges[i][0];
            ans[1] = edges[i][1];
            *returnSize = 2;
            return ans;
        }
        vis[edges[i][1]] =1;
    }
    return NULL;
}
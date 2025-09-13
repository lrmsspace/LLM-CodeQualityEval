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

int find(int* parent, int x) {
    if (parent[x - 1] != x) {
        parent[x - 1] = find(parent, parent[x - 1]);
    }
    return parent[x - 1];
}

void unionSet(int* parent, int* rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        if (rank[rootX - 1] < rank[rootY - 1]) {
            parent[rootX - 1] = rootY;
        } else {
            parent[rootY - 1] = rootX;
            if (rank[rootX - 1] == rank[rootY - 1]) {
                rank[rootX - 1]++;
            }
        }
    }
}

int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* parent = (int*)malloc(edgesSize * sizeof(int));
    for (int i = 0; i < edgesSize; ++i) {
        parent[i] = i + 1;
    }
    int* rank = (int*)malloc(edgesSize * sizeof(int));
    for (int i = 0; i < edgesSize; ++i) {
        rank[i] = 0;
    }
    
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < edgesSize; ++i) {
        int x = edges[i][0];
        int y = edges[i][1];
        if (parent[y - 1] != y) {
            result[0] = parent[y - 1];
            result[1] = y;
            *returnSize = 2;
            return result;
        }
        if (find(parent, x) == find(parent, y)) {
            result[0] = x;
            result[1] = y;
            *returnSize = 2;
            return result;
        }
        unionSet(parent, rank, x, y);
    }
    *returnSize = 2;
    return result;
}   
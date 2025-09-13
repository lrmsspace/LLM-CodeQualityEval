/*
 There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
 You must connect one node from the first tree with another node from the second tree with an edge.
 Return the minimum possible diameter of the resulting tree.
 The diameter of a tree is the length of the longest path between any two nodes in the tree.
 Example 1:
 Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]
 Output: 3
 Explanation:
 We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.
 Example 2:
 Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]
 Output: 5
 Explanation:
 We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.
 Constraints:
 1 <= n, m <= 105
 edges1.length == n - 1
 edges2.length == m - 1
 edges1[i].length == edges2[i].length == 2
 edges1[i] = [ai, bi]
 0 <= ai, bi < n
 edges2[i] = [ui, vi]
 0 <= ui, vi < m
 The input is generated such that edges1 and edges2 represent valid trees.
*/

int minimumDiameterAfterMerge(int** edges1, int edges1Size, int* edges1ColSize, int** edges2, int edges2Size, int* edges2ColSize) {
    int maxDepth1 = 0, maxDepth2 = 0;
    int maxNode1 = -1, maxNode2 = -1;
    int maxDepth12 = 0;
    
    void dfs1(int node, int depth) {
        if (depth > maxDepth1) {
            maxDepth1 = depth;
            maxNode1 = node;
        }
        for (int i = 0; i < edges1Size; ++i) {
            if (edges1[i][0] == node) {
                dfs1(edges1[i][1], depth + 1);
            }
        }
    }
    
    void dfs2(int node, int depth) {
        if (depth > maxDepth2) {
            maxDepth2 = depth;
            maxNode2 = node;
        }
        for (int i = 0; i < edges2Size; ++i) {
            if (edges2[i][0] == node) {
                dfs2(edges2[i][1], depth + 1);
            }
        }
    }
    
    void dfs12(int node, int depth) {
        if (depth > maxDepth12) {
            maxDepth12 = depth;
        }
        for (int i = 0; i < edges1Size; ++i) {
            if (edges1[i][0] == node) {
                dfs12(edges1[i][1], depth + 1);
            }
        }
        for (int i = 0; i < edges2Size; ++i) {
            if (edges2[i][0] == node) {
                dfs12(edges2[i][1], depth + 1);
            }
        }
    }
    
    dfs1(0, 0);
    dfs2(0, 0);
    dfs12(maxNode1, 0);
    return maxDepth1 + maxDepth2 - maxDepth12;
}
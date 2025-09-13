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

/**
 * @param {number[][]} edges1
 * @param {number[][]} edges2
 * @return {number}
 */
var minimumDiameterAfterMerge = function(edges1, edges2) {
    let n = edges1.length + 1;
    let m = edges2.length + 1;
    let depth1 = new Array(n).fill(0);
    let depth2 = new Array(m).fill(0);
    let maxDepth1 = 0, maxDepth2 = 0;
    let maxDepth1Node = -1, maxDepth2Node = -1;
    function dfs1(node, parent) {
        depth1[node] = Math.max(depth1[node], depth1[parent] + 1);
        if (depth1[node] > maxDepth1) {
            maxDepth1 = depth1[node];
            maxDepth1Node = node;
        }
        for (let edge of edges1) {
            if (edge[0] === node && edge[1] !== parent) {
                dfs1(edge[1], node);
            }
            if (edge[1] === node && edge[0] !== parent) {
                dfs1(edge[0], node);
            }
        }
    }
    function dfs2(node, parent) {
        depth2[node] = Math.max(depth2[node], depth2[parent] + 1);
        if (depth2[node] > maxDepth2) {
            maxDepth2 = depth2[node];
            maxDepth2Node = node;
        }
        for (let edge of edges2) {
            if (edge[0] === node && edge[1] !== parent) {
                dfs2(edge[1], node);
            }
            if (edge[1] === node && edge[0] !== parent) {
                dfs2(edge[0], node);
            }
        }
    }
    dfs1(0, -1);
    dfs2(0, -1);
    return Math.max(maxDepth1 + maxDepth2, depth1[maxDepth1Node] + depth2[maxDepth2Node]);
    
};
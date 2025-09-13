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
    const n = edges1.length + 1;
    const m = edges2.length + 1;
    const parent = new Array(n + m).fill(-1);
    const rank = new Array(n + m).fill(0);

    const find = (x) => {
        if (parent[x] === -1) {
            return x;
        }
        return parent[x] = find(parent[x]);
    };

    const union = (x, y) => {
        const rootX = find(x);
        const rootY = find(y);

        if (rootX === rootY) {
            return;
        }

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    };

    for (let i = 0; i < edges1.length; i++) {
        union(edges1[i][0], edges1[i][1] + n);
    }

    for (let i = 0; i < edges2.length; i++) {
        union(edges2[i][0], edges2[i][1] + n);
    }

    let minDiameter = Infinity;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (find(i) !== find(j + n)) {
                minDiameter = Math.min(minDiameter, Math.abs(i - (j + n)));
            }
        }
    }

    return minDiameter === Infinity ? -1 : minDiameter;
};
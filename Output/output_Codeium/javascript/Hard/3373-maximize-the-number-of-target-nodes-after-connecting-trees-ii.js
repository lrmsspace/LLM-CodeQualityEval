/*
 There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.
 You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
 Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.
 Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.
 Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.
 Example 1:
 Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
 Output: [8,7,7,8,8]
 Explanation:
 For i = 0, connect node 0 from the first tree to node 0 from the second tree.
 For i = 1, connect node 1 from the first tree to node 4 from the second tree.
 For i = 2, connect node 2 from the first tree to node 7 from the second tree.
 For i = 3, connect node 3 from the first tree to node 0 from the second tree.
 For i = 4, connect node 4 from the first tree to node 4 from the second tree.
 Example 2:
 Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]
 Output: [3,6,6,6,6]
 Explanation:
 For every i, connect node i of the first tree with any node of the second tree.
 Constraints:
 2 <= n, m <= 105
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
 * @return {number[]}
 */
var maxTargetNodes = function(edges1, edges2) {
    const n = edges1.length + 1;
    const m = edges2.length + 1;
    const answer = new Array(n).fill(0);
    const tree1 = new Array(n).fill(0).map(() => new Array());
    const tree2 = new Array(m).fill(0).map(() => new Array());
    
    for (const edge of edges1) {
        tree1[edge[0]].push(edge[1]);
        tree1[edge[1]].push(edge[0]);
    }
    
    for (const edge of edges2) {
        tree2[edge[0]].push(edge[1]);
        tree2[edge[1]].push(edge[0]);
    }
    
    for (let i = 0; i < n; i++) {
        let queue = [i];
        let visited = new Set([i]);
        while (queue.length) {
            const node = queue.shift();
            for (const neighbor of tree1[node]) {
                if (!visited.has(neighbor)) {
                    visited.add(neighbor);
                    queue.push(neighbor);
                }
            }
        }
        for (let j = 0; j < m; j++) {
            let queue2 = [j];
            let visited2 = new Set([j]);
            while (queue2.length) {
                const node = queue2.shift();
                for (const neighbor of tree2[node]) {
                    if (!visited2.has(neighbor)) {
                        visited2.add(neighbor);
                        queue2.push(neighbor);
                    }
                }
            }
            answer[i] = Math.max(answer[i], visited.size + visited2.size - 1);
        }
    }
    
    return answer;
};
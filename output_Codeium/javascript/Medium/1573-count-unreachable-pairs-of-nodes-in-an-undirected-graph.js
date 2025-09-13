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
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var countPairs = function(n, edges) {
    let parent = new Array(n).fill(0).map((v, i) => i);
    let rank = new Array(n).fill(0);

    for (let edge of edges) {
        let root1 = find(parent, edge[0]);
        let root2 = find(parent, edge[1]);
        if (root1 !== root2) {
            union(parent, rank, root1, root2);
        }
    }

    let count = 0;
    let map = new Map();
    for (let i = 0; i < n; i++) {
        let root = find(parent, i);
        if (!map.has(root)) {
            map.set(root, 0);
        }
        map.set(root, map.get(root) + 1);
        count += (n - map.get(root));
    }
    return count / 2;

    function find(parent, i) {
        if (parent[i] !== i) {
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }

    function union(parent, rank, x, y) {
        let rootX = find(parent, x);
        let rootY = find(parent, y);
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};
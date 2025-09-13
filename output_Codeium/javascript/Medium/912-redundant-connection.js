/**https://leetcode.com/problems/redundant-connection/ */
//In this problem, a tree is an undirected graph that is connected and has no cycles.
//You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
//Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
// 
//Example 1:
//Input: edges = [[1,2],[1,3],[2,3]]
//Output: [2,3]
//Example 2:
//Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
//Output: [1,4]
// 
//Constraints:
//	n == edges.length
//	3 <= n <= 1000
//	edges[i].length == 2
//	1 <= ai < bi <= edges.length
//	ai != bi
//	There are no repeated edges.
//	The given graph is connected.
/**
 * @param {number[][]} edges
 * @return {number[]}
 */
var findRedundantConnection = function(edges) {
    const uf = new UnionFind(edges.length + 1);
    for (const edge of edges) {
        if (!uf.union(edge[0], edge[1])) {
            return edge;
        }
    }
    return [];

    class UnionFind {
        constructor (n) {
            this.parent = Array.from({length: n}, (_, i) => i);
            this.rank = Array(n).fill(0);
        }

        find (x) {
            if (this.parent[x] === x) {
                return x;
            }
            this.parent[x] = this.find(this.parent[x]);
            return this.parent[x];
        }

        union (x, y) {
            const rootX = this.find(x);
            const rootY = this.find(y);
            if (rootX === rootY) {
                return false;
            }
            if (this.rank[rootX] < this.rank[rootY]) {
                this.parent[rootX] = rootY;
            } else if (this.rank[rootX] > this.rank[rootY]) {
                this.parent[rootY] = rootX;
            } else {
                this.parent[rootY] = rootX;
                this.rank[rootX]++;
            }
            return true;
        }
    }
};
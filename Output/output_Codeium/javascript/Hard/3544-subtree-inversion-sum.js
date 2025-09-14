/*
 You are given an undirected tree rooted at node 0, with n nodes numbered from 0 to n - 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates an edge between nodes ui and vi.
 You are also given an integer array nums of length n, where nums[i] represents the value at node i, and an integer k.
 You may perform inversion operations on a subset of nodes subject to the following rules:
 Subtree Inversion Operation:
 When you invert a node, every value in the subtree rooted at that node is multiplied by -1.
 Distance Constraint on Inversions:
 You may only invert a node if it is "sufficiently far" from any other inverted node.
 Specifically, if you invert two nodes a and b such that one is an ancestor of the other (i.e., if LCA(a, b) = a or LCA(a, b) = b), then the distance (the number of edges on the unique path between them) must be at least k.
 Return the maximum possible sum of the tree's node values after applying inversion operations.
 Example 1:
 Input: edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], nums = [4,-8,-6,3,7,-2,5], k = 2
 Output: 27
 Explanation:
 Apply inversion operations at nodes 0, 3, 4 and 6.
 The final nums array is [-4, 8, 6, 3, 7, 2, 5], and the total sum is 27.
 Example 2:
 Input: edges = [[0,1],[1,2],[2,3],[3,4]], nums = [-1,3,-2,4,-5], k = 2
 Output: 9
 Explanation:
 Apply the inversion operation at node 4.
 The final nums array becomes [-1, 3, -2, 4, 5], and the total sum is 9.
 Example 3:
 Input: edges = [[0,1],[0,2]], nums = [0,-1,-2], k = 3
 Output: 3
 Explanation:
 Apply inversion operations at nodes 1 and 2.
 Constraints:
 2 <= n <= 5 * 104
 edges.length == n - 1
 edges[i] = [ui, vi]
 0 <= ui, vi < n
 nums.length == n
 -5 * 104 <= nums[i] <= 5 * 104
 1 <= k <= 50
 The input is generated such that edges represents a valid tree.
*/

/**
 * @param {number[][]} edges
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subtreeInversionSum = function(edges, nums, k) {
    let n = nums.length;
    let depth = new Array(n).fill(0);
    let parent = new Array(n).fill(null).map(() => new Array(k).fill(null));
    let tree = new Array(n).fill(null).map(() => new Array());
    
    function dfs(node, prev, d) {
        depth[node] = d;
        parent[node][0] = prev;
        for (let i = 1; i < k; i++) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        }
        for (let child of tree[node]) {
            if (child !== prev) {
                dfs(child, node, d + 1);
            }
        }
    }
    
    for (let edge of edges) {
        tree[edge[0]].push(edge[1]);
        tree[edge[1]].push(edge[0]);
    }
    
    dfs(0, null, 0);
    
    let dp = new Array(n).fill(0);
    let visited = new Set();
    function dfs2(node, prev) {
        if (visited.has(node)) {
            return;
        }
        visited.add(node);
        dp[node] = nums[node];
        for (let child of tree[node]) {
            if (child !== prev) {
                dfs2(child, node);
                dp[node] += Math.max(dp[child], 0);
                dp[node] += Math.max(dp[parent[child][k - 1]] - dp[child], 0);
            }
        }
    }
    
    dfs2(0, null);
    
    return Math.max(...dp);
};
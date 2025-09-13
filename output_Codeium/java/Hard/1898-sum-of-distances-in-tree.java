/**https://leetcode.com/problems/sum-of-distances-in-tree/ */
//There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
//You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.
// 
//Example 1:
//Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
//Output: [8,12,6,10,10,10]
//Explanation: The tree is shown above.
//We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
//equals 1 + 1 + 2 + 2 + 2 = 8.
//Hence, answer[0] = 8, and so on.
//Example 2:
//Input: n = 1, edges = []
//Output: [0]
//Example 3:
//Input: n = 2, edges = [[1,0]]
//Output: [1,1]
// 
//Constraints:
//	1 <= n <= 3 * 104
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	The given input represents a valid tree.
class Solution {
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        int[] res = new int[n];
        int[] count = new int[n];
        int[][] graph = new int[n][n];
        for (int[] edge : edges) {
            graph[edge[0]][edge[1]] = graph[edge[1]][edge[0]] = 1;
        }
        dfs(graph, 0, -1, res, count);
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] + n - 2 * count[i];
        }
        return res;

    }

    private void dfs(int[][] graph, int node, int parent, int[] res, int[] count) {
        count[node] = 1;
        for (int i = 0; i < graph.length; i++) {
            if (graph[node][i] == 1 && i != parent) {
                dfs(graph, i, node, res, count);
                count[node] += count[i];
                res[node] += res[i] + count[i];
            }
        }
    }
}
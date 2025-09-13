/**https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/ */
//You are given an undirected graph. You are given an integer n which is the number of nodes in the graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.
//A connected trio is a set of three nodes where there is an edge between every pair of them.
//The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.
//Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.
// 
//Example 1:
//Input: n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
//Output: 3
//Explanation: There is exactly one trio, which is [1,2,3]. The edges that form its degree are bolded in the figure above.
//Example 2:
//Input: n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
//Output: 0
//Explanation: There are exactly three trios:
//1) [1,4,3] with degree 0.
//2) [2,5,6] with degree 2.
//3) [5,6,7] with degree 2.
// 
//Constraints:
//	2 <= n <= 400
//	edges[i].length == 2
//	1 <= edges.length <= n * (n-1) / 2
//	1 <= ui, vi <= n
//	ui != vi
//	There are no repeated edges.
class Solution {
    public int minTrioDegree(int n, int[][] edges) {
        // Create an adjacency list to represent the graph
        List<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        // Create a degree array to count the degree of each node
        int[] degree = new int[n + 1];
        
        // Fill the adjacency list and degree array
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].add(v);
            graph[v].add(u);
            degree[u]++;
            degree[v]++;
        }
        
        int minDegree = Integer.MAX_VALUE;
        
        // Check each node for connected trios
        for (int i = 1; i <= n; i++) {
            for (int j : graph[i]) {
                if (j > i) { // Avoid double counting edges
                    for (int k : graph[j]) {
                        if (k > j && graph[i].contains(k)) { // Check if i, j, k form a trio
                            int trioDegree = degree[i] + degree[j] + degree[k] - 6; // Subtract the edges in the trio
                            minDegree = Math.min(minDegree, trioDegree);
                        }
                    }
                }
            }
        }
        
        return minDegree == Integer.MAX_VALUE ? -1 : minDegree;   
    }
}
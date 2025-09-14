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
class Solution {
    public long countPairs(int n, int[][] edges) {
        // Initialize a list to keep track of the size of each connected component
        List<Integer> componentSizes = new ArrayList<>();
        
        // Create a boolean array to mark visited nodes
        boolean[] visited = new boolean[n];
        
        // Use a depth-first search to find each connected component
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int size = dfs(i, edges, visited);
                componentSizes.add(size);
            }
        }
        
        // Calculate the total number of pairs
        long totalPairs = (long) n * (n - 1) / 2;
        
        // Subtract the number of pairs within each component
        for (int size : componentSizes) {
            totalPairs -= (long) size * (size - 1) / 2;
        }
        
        return totalPairs;
    }
    
    private int dfs(int node, int[][] edges, boolean[] visited) {
        visited[node] = true;
        int size = 1;
        for (int[] edge : edges) {
            int neighbor = -1;
            if (edge[0] == node && !visited[edge[1]]) {
                neighbor = edge[1];
            } else if (edge[1] == node && !visited[edge[0]]) {
                neighbor = edge[0];
            }
            if (neighbor != -1) {
                size += dfs(neighbor, edges, visited);
            }
        }
        return size;
    }
        
}
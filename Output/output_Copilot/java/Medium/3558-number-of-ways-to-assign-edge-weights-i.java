/*
 There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
 Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
 The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
 Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.
 Since the answer may be large, return it modulo 109 + 7.
 Note: Ignore all edges not in the path from node 1 to x.
 Example 1:
 Input: edges = [[1,2]]
 Output: 1
 Explanation:
 The path from Node 1 to Node 2 consists of one edge (1 → 2).
 Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
 Example 2:
 Input: edges = [[1,2],[1,3],[3,4],[3,5]]
 Output: 2
 Explanation:
 The maximum depth is 2, with nodes 4 and 5 at the same depth. Either node can be selected for processing.
 For example, the path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4).
 Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
 Constraints:
 2 <= n <= 105
 edges.length == n - 1
 edges[i] == [ui, vi]
 1 <= ui, vi <= n
 edges represents a valid tree.
*/

class Solution {
    public int assignEdgeWeights(int[][] edges) {
        int n = edges.length + 1; // Number of nodes
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        // Build the graph
        for (int[] edge : edges) {
            graph[edge[0] - 1].add(edge[1] - 1);
            graph[edge[1] - 1].add(edge[0] - 1);
        }
        
        // Find the maximum depth and count the number of nodes at that depth
        boolean[] visited = new boolean[n];
        int maxDepth = 0;
        int countAtMaxDepth = 0;
        
        // DFS to find max depth and count nodes at that depth
        Stack<int[]> stack = new Stack<>();
        stack.push(new int[]{0, 0}); // {node, depth}
        
        while (!stack.isEmpty()) {
            int[] current = stack.pop();
            int node = current[0];
            int depth = current[1];
            
            if (visited[node]) continue;
            visited[node] = true;
            
            if (depth > maxDepth) {
                maxDepth = depth;
                countAtMaxDepth = 1; // Reset count for new max depth
            } else if (depth == maxDepth) {
                countAtMaxDepth++;
            }
            
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    stack.push(new int[]{neighbor, depth + 1});
                }
            }
        }
        
        // The number of ways to assign weights is 2^(countAtMaxDepth - 1)
        long result = (long) Math.pow(2, countAtMaxDepth - 1);
        
        return (int) (result % (1_000_000_007));
            
    }
}
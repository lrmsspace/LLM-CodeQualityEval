/*
 There is an undirected weighted graph with n vertices labeled from 0 to n - 1.
 You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.
 A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.
 The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.
 You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.
 Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.
 Example 1:
 Input: n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]
 Output: [1,-1]
 Explanation:
 To achieve the cost of 1 in the first query, we need to move on the following edges: 0->1 (weight 7), 1->2 (weight 1), 2->1 (weight 1), 1->3 (weight 7).
 In the second query, there is no walk between nodes 3 and 4, so the answer is -1.
 Example 2:
 Input: n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]
 Output: [0]
 Explanation:
 To achieve the cost of 0 in the first query, we need to move on the following edges: 1->2 (weight 1), 2->1 (weight 6), 1->2 (weight 1).
 Constraints:
 2 <= n <= 105
 0 <= edges.length <= 105
 edges[i].length == 3
 0 <= ui, vi <= n - 1
 ui != vi
 0 <= wi <= 105
 1 <= query.length <= 105
 query[i].length == 2
 0 <= si, ti <= n - 1
 si != ti
*/
class Solution {
    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        // Create a graph representation using adjacency list
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int[] edge : edges) {
            graph.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(new int[]{edge[1], edge[2]});
            graph.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(new int[]{edge[0], edge[2]});
        }

        // Result array for storing the minimum costs for each query
        int[] result = new int[query.length];
        
        // Process each query
        for (int i = 0; i < query.length; i++) {
            int start = query[i][0];
            int end = query[i][1];
            
            // Use Dijkstra's algorithm or a similar approach to find the minimum cost walk
            result[i] = findMinimumCost(graph, start, end, n);
        }

        return result;
    }

    private int findMinimumCost(Map<Integer, List<int[]>> graph, int start, int end, int n) {
        // Priority queue for Dijkstra's with custom comparator for minimum bitwise AND cost
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.offer(new int[]{start, Integer.MAX_VALUE});
        
        // Distance array to store the minimum cost to each node
        int[] minCost = new int[n];
        Arrays.fill(minCost, -1);
        minCost[start] = Integer.MAX_VALUE;

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int node = current[0];
            int cost = current[1];

            if (node == end) {
                return cost;
            }

            for (int[] neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                int nextNode = neighbor[0];
                int edgeWeight = neighbor[1];
                int newCost = cost & edgeWeight;

                if (newCost > minCost[nextNode]) {
                    minCost[nextNode] = newCost;
                    pq.offer(new int[]{nextNode, newCost});
                }
            }
        }

        return -1; // If no path is found
    }
}

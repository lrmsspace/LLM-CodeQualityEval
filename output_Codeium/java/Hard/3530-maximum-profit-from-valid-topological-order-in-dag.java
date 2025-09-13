/*
 You are given a Directed Acyclic Graph (DAG) with n nodes labeled from 0 to n - 1, represented by a 2D array edges, where edges[i] = [ui, vi] indicates a directed edge from node ui to vi. Each node has an associated score given in an array score, where score[i] represents the score of node i.
 You must process the nodes in a valid topological order. Each node is assigned a 1-based position in the processing order.
 The profit is calculated by summing up the product of each node's score and its position in the ordering.
 Return the maximum possible profit achievable with an optimal topological order.
 A topological order of a DAG is a linear ordering of its nodes such that for every directed edge u → v, node u comes before v in the ordering.
 Example 1:
 Input: n = 2, edges = [[0,1]], score = [2,3]
 Output: 8
 Explanation:
 Node 1 depends on node 0, so a valid order is [0, 1].
 Node
 Processing Order
 Score
 Multiplier
 Profit Calculation
 0
 1st
 2
 1
 2 × 1 = 2
 1
 2nd
 3
 2
 3 × 2 = 6
 The maximum total profit achievable over all valid topological orders is 2 + 6 = 8.
 Example 2:
 Input: n = 3, edges = [[0,1],[0,2]], score = [1,6,3]
 Output: 25
 Explanation:
 Nodes 1 and 2 depend on node 0, so the most optimal valid order is [0, 2, 1].
 Node
 Processing Order
 Score
 Multiplier
 Profit Calculation
 0
 1st
 1
 1
 1 × 1 = 1
 2
 2nd
 3
 2
 3 × 2 = 6
 1
 3rd
 6
 3
 6 × 3 = 18
 The maximum total profit achievable over all valid topological orders is 1 + 6 + 18 = 25.
 Constraints:
 1 <= n == score.length <= 22
 1 <= score[i] <= 105
 0 <= edges.length <= n * (n - 1) / 2
 edges[i] == [ui, vi] denotes a directed edge from ui to vi.
 0 <= ui, vi < n
 ui != vi
 The input graph is guaranteed to be a DAG.
 There are no duplicate edges.
*/
class Solution {
    public int maxProfit(int n, int[][] edges, int[] score) {
        // Create a graph and in-degree array
        List<List<Integer>> graph = new ArrayList<>();
        int[] inDegree = new int[n];
        
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        // Build the graph
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph.get(u).add(v);
            inDegree[v]++;
        }

        // Use a priority queue to process nodes in decreasing order of score
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                pq.offer(new int[]{i, score[i]});
            }
        }

        // Calculate maximum profit
        int[] position = new int[n];
        int order = 1;
        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int node = current[0];
            int nodeScore = current[1];
            position[node] = order++;
            
            for (int neighbor : graph.get(node)) {
                if (--inDegree[neighbor] == 0) {
                    pq.offer(new int[]{neighbor, score[neighbor]});
                }
            }
        }

        // Sum up the products of scores and positions
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit += score[i] * position[i];
        }

        return maxProfit;
    }
}

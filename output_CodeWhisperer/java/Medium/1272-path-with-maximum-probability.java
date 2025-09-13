/**https://leetcode.com/problems/path-with-maximum-probability/ */
//You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
//Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
//If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.
// 
//Example 1:
//Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
//Output: 0.25000
//Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
//Example 2:
//Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
//Output: 0.30000
//Example 3:
//Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
//Output: 0.00000
//Explanation: There is no path between 0 and 2.
// 
//Constraints:
//	2 <= n <= 10^4
//	0 <= start, end < n
//	start != end
//	0 <= a, b < n
//	a != b
//	0 <= succProb.length == edges.length <= 2*10^4
//	0 <= succProb[i] <= 1
//	There is at most one edge between every two nodes.
class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        Map<Integer, Map<Integer, Double>> graph = new HashMap<>();
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            graph.computeIfAbsent(u, k -> new HashMap<>()).put(v, w);
            graph.computeIfAbsent(v, k -> new HashMap<>()).put(u, w);
        }
        double[] prob = new double[n];
        prob[start_node] = 1.0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> Double.compare(prob[b], prob[a]));
        pq.offer(start_node);
        while (!pq.isEmpty()) {
            int u = pq.poll();
            if (u == end_node) {
                return prob[u];
            }
            for (Map.Entry<Integer, Double> entry : graph.getOrDefault(u, new HashMap<>()).entrySet()) {
                int v = entry.getKey();
                double w = entry.getValue();
                if (prob[u] * w > prob[v]) {
                    prob[v] = prob[u] * w;
                    pq.offer(v);
                }
            }
        }
        return 0.0;     
    }
}
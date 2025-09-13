/**https://leetcode.com/problems/modify-graph-edge-weights/ */
//You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.
//Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).
//Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.
//Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.
//Note: You are not allowed to modify the weights of edges with initial positive weights.
// 
//Example 1:
//Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
//Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
//Explanation: The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.
//Example 2:
//Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
//Output: []
//Explanation: The graph above contains the initial edges. It is not possible to make the distance from 0 to 2 equal to 6 by modifying the edge with weight -1. So, an empty array is returned.
//Example 3:
//Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
//Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
//Explanation: The graph above shows a modified graph having the shortest distance from 0 to 2 as 6.
// 
//Constraints:
//	1 <= n <= 100
//	1 <= edges.length <= n * (n - 1) / 2
//	edges[i].length == 3
//	0 <= ai, bi < n
//	wi = -1 or 1 <= wi <= 107
//	ai != bi
//	0 <= source, destination < n
//	source != destination
//	1 <= target <= 109
//	The graph is connected, and there are no self-loops or repeated edges
class Solution {
    private static final long INF = Long.MAX_VALUE / 2;
    
    public int[][] modifiedGraphEdges(int n, int[][] edges, int source, int destination, int target) {
        // Create adjacency lists for both original and modified graphs
        List<List<Pair<Integer, Long>>> originalGraph = new ArrayList<>();
        List<List<Pair<Integer, Long>>> modifiedGraph = new ArrayList<>();
        
        // Initialize adjacency lists
        for (int i = 0; i < n; i++) {
            originalGraph.add(new ArrayList<>());
            modifiedGraph.add(new ArrayList<>());
        }
        
        // Build both graphs
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (w != -1) {
                // For positive weights, add to both graphs
                originalGraph.get(u).add(new Pair<>(v, (long)w));
                originalGraph.get(v).add(new Pair<>(u, (long)w));
                modifiedGraph.get(u).add(new Pair<>(v, (long)w));
                modifiedGraph.get(v).add(new Pair<>(u, (long)w));
            } else {
                // For -1 weights, add maximum weight to modified graph
                modifiedGraph.get(u).add(new Pair<>(v, (long)2e9));
                modifiedGraph.get(v).add(new Pair<>(u, (long)2e9));
            }
        }
        
        // Find shortest path in original graph (with -1 edges set to 1)
        long[] distOriginal = dijkstra(originalGraph, source, n);
        if (distOriginal[destination] > target) {
            return new int[0]; // Impossible: shortest possible path > target
        }
        
        // Find shortest path in modified graph (with -1 edges set to 2e9)
        long[] distModified = dijkstra(modifiedGraph, source, n);
        if (distModified[destination] < target) {
            return new int[0]; // Impossible: longest possible path < target
        }
        
        // Process each edge to achieve target distance
        for (int[] edge : edges) {
            if (edge[2] == -1) {
                edge[2] = (int)2e9; // Start with maximum weight
            }
        }
        
        // Find the critical edge that needs exact weight
        for (int i = 0; i < edges.length; i++) {
            if (edges[i][2] == (int)2e9) {
                int u = edges[i][0], v = edges[i][1];
                
                // Try to find appropriate weight for this edge
                long requiredWeight = findRequiredWeight(edges, i, source, destination, n, target);
                if (requiredWeight >= 1 && requiredWeight <= 2e9) {
                    edges[i][2] = (int)requiredWeight;
                    // Set remaining -1 edges to 1
                    for (int j = i + 1; j < edges.length; j++) {
                        if (edges[j][2] == (int)2e9) {
                            edges[j][2] = 1;
                        }
                    }
                    return edges;
                }
            }
        }
        
        return new int[0];
    }
    
    private long[] dijkstra(List<List<Pair<Integer, Long>>> graph, int source, int n) {
        long[] dist = new long[n];
        Arrays.fill(dist, INF);
        dist[source] = 0;
        
        PriorityQueue<Pair<Long, Integer>> pq = new PriorityQueue<>(
            (a, b) -> Long.compare(a.getKey(), b.getKey())
        );
        pq.offer(new Pair<>(0L, source));
        
        while (!pq.isEmpty()) {
            Pair<Long, Integer> curr = pq.poll();
            long d = curr.getKey();
            int u = curr.getValue();
            
            if (d > dist[u]) continue;
            
            for (Pair<Integer, Long> next : graph.get(u)) {
                int v = next.getKey();
                long w = next.getValue();
                
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.offer(new Pair<>(dist[v], v));
                }
            }
        }
        
        return dist;
    }
    
    private long findRequiredWeight(int[][] edges, int currentEdge, int source, 
                                  int destination, int n, int target) {
        // Create temporary graph for testing
        List<List<Pair<Integer, Long>>> tempGraph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            tempGraph.add(new ArrayList<>());
        }
        
        // Add all edges except current edge
        for (int i = 0; i < edges.length; i++) {
            if (i != currentEdge) {
                int u = edges[i][0], v = edges[i][1], w = edges[i][2];
                tempGraph.get(u).add(new Pair<>(v, (long)w));
                tempGraph.get(v).add(new Pair<>(u, (long)w));
            }
        }
        
        // Find current shortest path without this edge
        long[] dist = dijkstra(tempGraph, source, n);
        if (dist[destination] == INF) return -1;
        
        // Calculate required weight
        int u = edges[currentEdge][0], v = edges[currentEdge][1];
        long minDist = Math.min(
            dist[u] + dist[destination], 
            dist[v] + dist[destination]
        );
        
        return target - minDist;
    }
    
    // Simple Pair class implementation
    private static class Pair<K, V> {
        private final K key;
        private final V value;
        
        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }
        
        public K getKey() { return key; }
        public V getValue() { return value; }
    }
}

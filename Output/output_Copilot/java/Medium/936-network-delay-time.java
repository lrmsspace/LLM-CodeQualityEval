/**https://leetcode.com/problems/network-delay-time/ */
//You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
//We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
// 
//Example 1:
//Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
//Output: 2
//Example 2:
//Input: times = [[1,2,1]], n = 2, k = 1
//Output: 1
//Example 3:
//Input: times = [[1,2,1]], n = 2, k = 2
//Output: -1
// 
//Constraints:
//	1 <= k <= n <= 100
//	1 <= times.length <= 6000
//	times[i].length == 3
//	1 <= ui, vi <= n
//	ui != vi
//	0 <= wi <= 100
//	All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        // Create a graph from the times array
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int[] time : times) {
            graph.computeIfAbsent(time[0], x -> new ArrayList<>()).add(new int[]{time[1], time[2]});
        }

        // Dijkstra's algorithm to find the shortest path from node k to all other nodes
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.offer(new int[]{k, 0});
        boolean[] visited = new boolean[n + 1];
        int maxTime = 0;

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int node = current[0], time = current[1];

            if (visited[node]) continue;
            visited[node] = true;
            maxTime = Math.max(maxTime, time);

            for (int[] neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                if (!visited[neighbor[0]]) {
                    pq.offer(new int[]{neighbor[0], time + neighbor[1]});
                }
            }
        }

        // Check if all nodes were visited
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) return -1;
        }

        return maxTime;        
    }
}
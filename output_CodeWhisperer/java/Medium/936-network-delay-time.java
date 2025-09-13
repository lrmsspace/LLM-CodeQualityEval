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
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int[] time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph.computeIfAbsent(u, x -> new ArrayList<>()).add(new int[]{v, w});
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.offer(new int[]{k, 0});
        Map<Integer, Integer> dist = new HashMap<>();
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int u = curr[0], d = curr[1];
            if (dist.containsKey(u)) continue;
            dist.put(u, d);
            if (graph.containsKey(u)) {
                for (int[] neighbor : graph.get(u)) {
                    int v = neighbor[0], w = neighbor[1];
                    if (!dist.containsKey(v)) {
                        pq.offer(new int[]{v, d + w});
                    }
                }
            }
        }
        if (dist.size() != n) return -1;
        int max = 0;
        for (int d : dist.values()) {
            max = Math.max(max, d);
        }
        return max;       
    }
}
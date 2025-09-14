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
        int[][] graph = new int[n+1][n+1];
        for (int[] edge : times) {
            graph[edge[0]][edge[1]] = edge[2];
        }
        
        int[] distance = new int[n+1];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[k] = 0;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, k});
        
        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int currentDistance = current[0];
            int currentNode = current[1];
            
            if (currentDistance > distance[currentNode]) continue;
            
            for (int neighbor = 1; neighbor <= n; neighbor++) {
                int edgeDistance = graph[currentNode][neighbor];
                if (edgeDistance == 0) continue;
                
                int newDistance = currentDistance + edgeDistance;
                if (newDistance < distance[neighbor]) {
                    distance[neighbor] = newDistance;
                    pq.offer(new int[]{newDistance, neighbor});
                }
            }
        }
        
        int maxDistance = Arrays.stream(distance).max().getAsInt();
        return maxDistance == Integer.MAX_VALUE? -1 : maxDistance;
        
    }
}
/**https://leetcode.com/problems/find-closest-node-to-given-two-nodes/ */
//You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
//The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.
//You are also given two integers node1 and node2.
//Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.
//Note that edges may contain cycles.
// 
//Example 1:
//Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
//Output: 2
//Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
//The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
//Example 2:
//Input: edges = [1,2,-1], node1 = 0, node2 = 2
//Output: 2
//Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
//The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.
// 
//Constraints:
//	n == edges.length
//	2 <= n <= 105
//	-1 <= edges[i] < n
//	edges[i] != i
//	0 <= node1, node2 < n
class Solution {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int n = edges.length;
        int[] dist1 = new int[n];
        int[] dist2 = new int[n];
        Arrays.fill(dist1, Integer.MAX_VALUE);
        Arrays.fill(dist2, Integer.MAX_VALUE);
        
        dist1[node1] = 0;
        dist2[node2] = 0;
        
        Queue<Integer> queue1 = new ArrayDeque<>();
        queue1.offer(node1);
        
        Queue<Integer> queue2 = new ArrayDeque<>();
        queue2.offer(node2);
        
        while (!queue1.isEmpty() ||!queue2.isEmpty()) {
            int size1 = queue1.size();
            for (int i = 0; i < size1; i++) {
                int cur = queue1.poll();
                int[] neighbors = getNeighbors(edges, cur);
                for (int neighbor : neighbors) {
                    if (neighbor == -1) continue;
                    int newDist = dist1[cur] + 1;
                    if (newDist < dist1[neighbor]) {
                        dist1[neighbor] = newDist;
                        queue1.offer(neighbor);
                    }
                }
            }
            
            int size2 = queue2.size();
            for (int i = 0; i < size2; i++) {
                int cur = queue2.poll();
                int[] neighbors = getNeighbors(edges, cur);
                for (int neighbor : neighbors) {
                    if (neighbor == -1) continue;
                    int newDist = dist2[cur] + 1;
                    if (newDist < dist2[neighbor]) {
                        dist2[neighbor] = newDist;
                        queue2.offer(neighbor);
                    }
                }
            }
        
            if (queue1.isEmpty() && queue2.isEmpty()) {
                break;
            }
        }
        
        int minDist = Integer.MAX_VALUE;
        int closestNode = -1;
        for (int i = 0; i < n; i++) {
            if (dist1[i]!= Integer.MAX_VALUE && dist2[i]!= Integer.MAX_VALUE) {
                int maxDist = Math.max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    closestNode = i;
                }
            }
        }
        
        return closestNode;
        
    }
}
/**https://leetcode.com/problems/shortest-path-visiting-all-nodes/ */
//You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.
//Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
// 
//Example 1:
//Input: graph = [[1,2,3],[0],[0],[0]]
//Output: 4
//Explanation: One possible path is [1,0,2,0,3]
//Example 2:
//Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
//Output: 4
//Explanation: One possible path is [0,1,4,2,3]
// 
//Constraints:
//	n == graph.length
//	1 <= n <= 12
//	0 <= graph[i].length < n
//	graph[i] does not contain i.
//	If graph[a] contains b, then graph[b] contains a.
//	The input graph is always connected.
import java.util.LinkedList;
import java.util.Arrays;
import java.util.Queue;
class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        int[][] dp = new int[n][1<<n];
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
            dp[i][1<<i] = 0;
            queue.offer(new int[]{i, 1<<i});
        }
        
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int node = cur[0], state = cur[1], cost = dp[node][state];
            if (state == (1<<n)-1) {
                return cost;
            }
            for (int next : graph[node]) {
                int nextState = state | (1<<next);
                if (dp[next][nextState] > cost+1) {
                    dp[next][nextState] = cost+1;
                    queue.offer(new int[]{next, nextState});
                }
            }
        }
        return -1;      
    }
}
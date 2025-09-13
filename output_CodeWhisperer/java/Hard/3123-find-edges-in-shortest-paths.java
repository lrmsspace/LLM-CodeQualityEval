/*
import java.util.PriorityQueue;
import java.util.Arrays;
 You are given an undirected weighted graph of n nodes numbered from 0 to n - 1. The graph consists of m edges represented by a 2D array edges, where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.
 Consider all the shortest paths from node 0 to node n - 1 in the graph. You need to find a boolean array answer where answer[i] is true if the edge edges[i] is part of at least one shortest path. Otherwise, answer[i] is false.
 Return the array answer.
 Note that the graph may not be connected.
 Example 1:
 Input: n = 6, edges = [[0,1,4],[0,2,1],[1,3,2],[1,4,3],[1,5,1],[2,3,1],[3,5,3],[4,5,2]]
 Output: [true,true,true,false,true,true,true,false]
 Explanation:
 The following are all the shortest paths between nodes 0 and 5:
 The path 0 -> 1 -> 5: The sum of weights is 4 + 1 = 5.
 The path 0 -> 2 -> 3 -> 5: The sum of weights is 1 + 1 + 3 = 5.
 The path 0 -> 2 -> 3 -> 1 -> 5: The sum of weights is 1 + 1 + 2 + 1 = 5.
 Example 2:
 Input: n = 4, edges = [[2,0,1],[0,1,1],[0,3,4],[3,2,2]]
 Output: [true,false,false,true]
 Explanation:
 There is one shortest path between nodes 0 and 3, which is the path 0 -> 2 -> 3 with the sum of weights 1 + 2 = 3.
 Constraints:
 2 <= n <= 5 * 104
 m == edges.length
 1 <= m <= min(5 * 104, n * (n - 1) / 2)
 0 <= ai, bi < n
 ai != bi
 1 <= wi <= 105
 There are no repeated edges.
*/

class Solution {
    public boolean[] findAnswer(int n, int[][] edges) {
        int[][] graph = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(graph[i], Integer.MAX_VALUE);
        }
        for (int[] edge : edges) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.offer(new int[]{0, 0});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int node = cur[0];
            int d = cur[1];
            if (d > dist[node]) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                if (graph[node][i] != Integer.MAX_VALUE) {
                    int newDist = d + graph[node][i];
                    if (newDist < dist[i]) {
                        dist[i] = newDist;
                            pq.offer(new int[]{i, newDist});
                    }
                }
            }
        }
        boolean[] answer = new boolean[edges.length];
        for (int i = 0; i < edges.length; i++) {
            int[] edge = edges[i];
            if (dist[edge[0]] == Integer.MAX_VALUE || dist[edge[1]] == Integer.MAX_VALUE) {
                continue;
            }
            if (dist[edge[0]] + edge[2] == dist[edge[1]] || dist[edge[1]] + edge[2] == dist[edge[0]]) {
                answer[i] = true;
            }
        }
        return answer;        
    }
}
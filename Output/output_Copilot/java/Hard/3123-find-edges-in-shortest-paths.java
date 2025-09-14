/*
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
        int m = edges.length;
        boolean[] answer = new boolean[m];
        int[] dist = new int[n];
        int[] prevCount = new int[n];
        int[] nextCount = new int[n];
        List<int[]>[] graph = new List[n];

        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
            dist[i] = Integer.MAX_VALUE;
            prevCount[i] = 0;
            nextCount[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            graph[u].add(new int[]{v, w});
            graph[v].add(new int[]{u, w});
        }

        dist[0] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);
        
        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int[] neighbor : graph[node]) {
                int nextNode = neighbor[0], weight = neighbor[1];
                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    prevCount[nextNode] = 1;
                    nextCount[nextNode] = 1;
                    queue.offer(nextNode);
                } else if (dist[node] + weight == dist[nextNode]) {
                    prevCount[nextNode]++;
                    nextCount[nextNode]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (dist[u] + w == dist[v] && prevCount[u] > 0 && nextCount[v] > 0) {
                answer[i] = true;
            } else if (dist[v] + w == dist[u] && prevCount[v] > 0 && nextCount[u] > 0) {
                answer[i] = true;
            }
        }

        return answer;
            
    }
}
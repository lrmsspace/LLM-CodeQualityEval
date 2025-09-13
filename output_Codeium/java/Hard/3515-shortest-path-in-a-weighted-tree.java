/*
 You are given an integer n and an undirected, weighted tree rooted at node 1 with n nodes numbered from 1 to n. This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, wi] indicates an undirected edge from node ui to vi with weight wi.
 You are also given a 2D integer array queries of length q, where each queries[i] is either:
 [1, u, v, w'] – Update the weight of the edge between nodes u and v to w', where (u, v) is guaranteed to be an edge present in edges.
 [2, x] – Compute the shortest path distance from the root node 1 to node x.
 Return an integer array answer, where answer[i] is the shortest path distance from node 1 to x for the ith query of [2, x].
 Example 1:
 Input: n = 2, edges = [[1,2,7]], queries = [[2,2],[1,1,2,4],[2,2]]
 Output: [7,4]
 Explanation:
 Query [2,2]: The shortest path from root node 1 to node 2 is 7.
 Query [1,1,2,4]: The weight of edge (1,2) changes from 7 to 4.
 Query [2,2]: The shortest path from root node 1 to node 2 is 4.
 Example 2:
 Input: n = 3, edges = [[1,2,2],[1,3,4]], queries = [[2,1],[2,3],[1,1,3,7],[2,2],[2,3]]
 Output: [0,4,2,7]
 Explanation:
 Query [2,1]: The shortest path from root node 1 to node 1 is 0.
 Query [2,3]: The shortest path from root node 1 to node 3 is 4.
 Query [1,1,3,7]: The weight of edge (1,3) changes from 4 to 7.
 Query [2,2]: The shortest path from root node 1 to node 2 is 2.
 Query [2,3]: The shortest path from root node 1 to node 3 is 7.
 Example 3:
 Input: n = 4, edges = [[1,2,2],[2,3,1],[3,4,5]], queries = [[2,4],[2,3],[1,2,3,3],[2,2],[2,3]]
 Output: [8,3,2,5]
 Explanation:
 Query [2,4]: The shortest path from root node 1 to node 4 consists of edges (1,2), (2,3), and (3,4) with weights 2 + 1 + 5 = 8.
 Query [2,3]: The shortest path from root node 1 to node 3 consists of edges (1,2) and (2,3) with weights 2 + 1 = 3.
 Query [1,2,3,3]: The weight of edge (2,3) changes from 1 to 3.
 Query [2,2]: The shortest path from root node 1 to node 2 is 2.
 Query [2,3]: The shortest path from root node 1 to node 3 consists of edges (1,2) and (2,3) with updated weights 2 + 3 = 5.
 Constraints:
 1 <= n <= 105
 edges.length == n - 1
 edges[i] == [ui, vi, wi]
 1 <= ui, vi <= n
 1 <= wi <= 104
 The input is generated such that edges represents a valid tree.
 1 <= queries.length == q <= 105
 queries[i].length == 2 or 4
 queries[i] == [1, u, v, w'] or,
 queries[i] == [2, x]
 1 <= u, v, x <= n
 (u, v) is always an edge from edges.
 1 <= w' <= 104
*/

class Solution {
    public int[] treeQueries(int n, int[][] edges, int[][] queries) {
        // Initialize adjacency list for the tree
        List<int[]>[] graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        // Populate the adjacency list with the edges
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].add(new int[]{v, w});
            graph[v].add(new int[]{u, w});
        }

        // Array to store the shortest path from root to each node
        int[] dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[1] = 0; // Distance to the root is 0

        // Use a priority queue to facilitate Dijkstra's algorithm
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.offer(new int[]{1, 0}); // Start from the root node

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int node = current[0], currentDist = current[1];

            if (currentDist > dist[node]) continue;

            for (int[] neighbor : graph[node]) {
                int nextNode = neighbor[0], weight = neighbor[1];
                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    pq.offer(new int[]{nextNode, dist[nextNode]});
                }
            }
        }

        // Process the queries
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            if (query[0] == 1) {
                // Update the weight of the edge and re-run Dijkstra
                int u = query[1], v = query[2], newWeight = query[3];
                for (int[] neighbor : graph[u]) {
                    if (neighbor[0] == v) {
                        neighbor[1] = newWeight;
                        break;
                    }
                }
                for (int[] neighbor : graph[v]) {
                    if (neighbor[0] == u) {
                        neighbor[1] = newWeight;
                        break;
                    }
                }
                // Reset distances and re-run Dijkstra after updating the edge weight
                Arrays.fill(dist, Integer.MAX_VALUE);
                dist[1] = 0;
                pq.clear();
                pq.offer(new int[]{1, 0});
                while (!pq.isEmpty()) {
                    int[] current = pq.poll();
                    int node = current[0], currentDist = current[1];

                    if (currentDist > dist[node]) continue;

                    for (int[] neighbor : graph[node]) {
                        int nextNode = neighbor[0], weight = neighbor[1];
                        if (dist[node] + weight < dist[nextNode]) {
                            dist[nextNode] = dist[node] + weight;
                            pq.offer(new int[]{nextNode, dist[nextNode]});
                        }
                    }
                }
            } else if (query[0] == 2) {
                // Get the shortest path distance from root to node x
                int x = query[1];
                result[i] = dist[x];
            }
        }
        return result;

    }
}
/**https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/ */
//You are given an integer n denoting the number of nodes of a weighted directed graph. The nodes are numbered from 0 to n - 1.
//You are also given a 2D integer array edges where edges[i] = [fromi, toi, weighti] denotes that there exists a directed edge from fromi to toi with weight weighti.
//Lastly, you are given three distinct integers src1, src2, and dest denoting three distinct nodes of the graph.
//Return the minimum weight of a subgraph of the graph such that it is possible to reach dest from both src1 and src2 via a set of edges of this subgraph. In case such a subgraph does not exist, return -1.
//A subgraph is a graph whose vertices and edges are subsets of the original graph. The weight of a subgraph is the sum of weights of its constituent edges.
// 
//Example 1:
//Input: n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5
//Output: 9
//Explanation:
//The above figure represents the input graph.
//The blue edges represent one of the subgraphs that yield the optimal answer.
//Note that the subgraph [[1,0,3],[0,5,6]] also yields the optimal answer. It is not possible to get a subgraph with less weight satisfying all the constraints.
//Example 2:
//Input: n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
//Output: -1
//Explanation:
//The above figure represents the input graph.
//It can be seen that there does not exist any path from node 1 to node 2, hence there are no subgraphs satisfying all the constraints.
// 
//Constraints:
//	3 <= n <= 105
//	0 <= edges.length <= 105
//	edges[i].length == 3
//	0 <= fromi, toi, src1, src2, dest <= n - 1
//	fromi != toi
//	src1, src2, and dest are pairwise distinct.
//	1 <= weight[i] <= 105
        typedef struct {
            int to;
            int weight;
        } Edge;

        typedef struct {
            Edge* edges;
            int size;
            int capacity;
        } AdjList;

        void addEdge(AdjList* graph, int from, int to, int weight) {
            if (graph[from].size == graph[from].capacity) {
                graph[from].capacity *= 2;
                graph[from].edges = realloc(graph[from].edges, graph[from].capacity * sizeof(Edge));
            }
            graph[from].edges[graph[from].size++] = (Edge){to, weight};
        }

        void dijkstra(AdjList* graph, int n, int src, long long* dist) {
            int* visited = calloc(n, sizeof(int));
            for (int i = 0; i < n; i++) dist[i] = LLONG_MAX;
            dist[src] = 0;

            for (int i = 0; i < n; i++) {
                long long minDist = LLONG_MAX;
                int u = -1;
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && dist[j] < minDist) {
                        minDist = dist[j];
                        u = j;
                    }
                }
                if (u == -1) break;
                visited[u] = 1;

                for (int j = 0; j < graph[u].size; j++) {
                    Edge edge = graph[u].edges[j];
                    if (dist[u] != LLONG_MAX && dist[u] + edge.weight < dist[edge.to]) {
                        dist[edge.to] = dist[u] + edge.weight;
                    }
                }
            }

            free(visited);
        }

        long long minimumWeight(int n, int** edges, int edgesSize, int* edgesColSize, int src1, int src2, int dest) {
            AdjList* graph = calloc(n, sizeof(AdjList));
            AdjList* reverseGraph = calloc(n, sizeof(AdjList));
            for (int i = 0; i < n; i++) {
                graph[i].edges = malloc(2 * sizeof(Edge));
                graph[i].capacity = 2;
                reverseGraph[i].edges = malloc(2 * sizeof(Edge));
                reverseGraph[i].capacity = 2;
            }

            for (int i = 0; i < edgesSize; i++) {
                int from = edges[i][0], to = edges[i][1], weight = edges[i][2];
                addEdge(graph, from, to, weight);
                addEdge(reverseGraph, to, from, weight);
            }

            long long* distFromSrc1 = malloc(n * sizeof(long long));
            long long* distFromSrc2 = malloc(n * sizeof(long long));
            long long* distToDest = malloc(n * sizeof(long long));

            dijkstra(graph, n, src1, distFromSrc1);
            dijkstra(graph, n, src2, distFromSrc2);
            dijkstra(reverseGraph, n, dest, distToDest);

            long long minWeight = LLONG_MAX;
            for (int i = 0; i < n; i++) {
                if (distFromSrc1[i] != LLONG_MAX && distFromSrc2[i] != LLONG_MAX && distToDest[i] != LLONG_MAX) {
                    long long totalWeight = distFromSrc1[i] + distFromSrc2[i] + distToDest[i];
                    if (totalWeight < minWeight) {
                        minWeight = totalWeight;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                free(graph[i].edges);
                free(reverseGraph[i].edges);
            }
            free(graph);
            free(reverseGraph);
            free(distFromSrc1);
            free(distFromSrc2);
            free(distToDest);

            return minWeight == LLONG_MAX ? -1 : minWeight;
        }

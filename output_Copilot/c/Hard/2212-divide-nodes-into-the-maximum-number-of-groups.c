/**https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/ */
//You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.
//You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.
//Divide the nodes of the graph into m groups (1-indexed) such that:
//	Each node in the graph belongs to exactly one group.
//	For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
//Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.
// 
//Example 1:
//Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
//Output: 4
//Explanation: As shown in the image we:
//- Add node 5 to the first group.
//- Add node 1 to the second group.
//- Add nodes 2 and 4 to the third group.
//- Add nodes 3 and 6 to the fourth group.
//We can see that every edge is satisfied.
//It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.
//Example 2:
//Input: n = 3, edges = [[1,2],[2,3],[3,1]]
//Output: -1
//Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
//It can be shown that no grouping is possible.
// 
//Constraints:
//	1 <= n <= 500
//	1 <= edges.length <= 104
//	edges[i].length == 2
//	1 <= ai, bi <= n
//	ai != bi
//	There is at most one edge between any pair of vertices.
int magnificentSets(int n, int** edges, int edgesSize, int* edgesColSize) {
        #include <stdbool.h>
        #include <stdlib.h>
        #include <string.h>

        #define MAX_NODES 500

        typedef struct {
            int nodes[MAX_NODES];
            int size;
        } Queue;

        void enqueue(Queue* q, int value) {
            q->nodes[q->size++] = value;
        }

        int dequeue(Queue* q) {
            return q->nodes[--q->size];
        }

        bool bfs(int start, int* groups, int** graph, int* graphSize, int n) {
            Queue q = { .size = 0 };
            enqueue(&q, start);
            groups[start] = 1;

            while (q.size > 0) {
                int node = dequeue(&q);
                for (int i = 0; i < graphSize[node]; i++) {
                    int neighbor = graph[node][i];
                    if (groups[neighbor] == 0) {
                        groups[neighbor] = groups[node] + 1;
                        enqueue(&q, neighbor);
                    } else if (abs(groups[neighbor] - groups[node]) != 1) {
                        return false;
                    }
                }
            }
            return true;
        }

        int magnificentSets(int n, int** edges, int edgesSize, int* edgesColSize) {
            int** graph = (int**)malloc((n + 1) * sizeof(int*));
            int* graphSize = (int*)calloc(n + 1, sizeof(int));
            for (int i = 0; i <= n; i++) {
                graph[i] = (int*)malloc(MAX_NODES * sizeof(int));
            }

            for (int i = 0; i < edgesSize; i++) {
                int u = edges[i][0], v = edges[i][1];
                graph[u][graphSize[u]++] = v;
                graph[v][graphSize[v]++] = u;
            }

            int* groups = (int*)calloc(n + 1, sizeof(int));
            int maxGroups = 0;

            for (int i = 1; i <= n; i++) {
                if (groups[i] == 0) {
                    if (!bfs(i, groups, graph, graphSize, n)) {
                        maxGroups = -1;
                        break;
                    }
                }
            }

            if (maxGroups != -1) {
                for (int i = 1; i <= n; i++) {
                    if (groups[i] > maxGroups) {
                        maxGroups = groups[i];
                    }
                }
            }

            for (int i = 0; i <= n; i++) {
                free(graph[i]);
            }
            free(graph);
            free(graphSize);
            free(groups);

            return maxGroups;
        }
}   
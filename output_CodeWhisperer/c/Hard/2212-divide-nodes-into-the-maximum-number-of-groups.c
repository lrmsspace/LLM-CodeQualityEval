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
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, len, min, max, count, target, sum, ans;

    len = edgesSize;
    int** graph = (int**)malloc(sizeof(int*) * n);

    for (i = 0; i < n; i++) {
        graph[i] = (int*)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (i = 0; i < len; i++) {
        graph[edges[i][0] - 1][edges[i][1] - 1] = 1;
        graph[edges[i][1] - 1][edges[i][0] - 1] = 1;
    }

    int* visited = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int* queue = (int*)malloc(sizeof(int) * n);

    int* distance = (int*)malloc(sizeof(int) * n);

    int* groups = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        groups[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            queue[0] = i;
            count = 1;
            groups[i] = 1;
            for (j = 0; j < count; j++) {
                for (k = 0; k < n; k++) {
                    if (graph[queue[j]][k] == 1 && visited[k] == 0) {
                        visited[k] = 1;
                        queue[count] = k;
                        count++;
                        groups[k] = 1;
                    }
                }
            }
            for (j = 0; j < count; j++) {
                for (k = 0; k < n; k++) {
                    distance[k] = -1;
                }
                distance[queue[j]] = 0;
                for (k = 0; k < count; k++) {
                    for (l = 0; l < n; l++) {
                        if (graph[queue[k]][l] == 1) {
                            if (distance[l] == -1) {
                                distance[l] = distance[queue[k]] + 1;
                            } else {
                                distance[l] = min(distance[l], distance[queue[k]] + 1);
                            }
                        }
                    }
                }
                for (k = 0; k < n; k++) {
                    if (distance[k] == -1) {
                        return -1;
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            queue[0] = i;
            count = 1;
            for (j = 0; j < count; j++) {
                for (k = 0; k < n; k++) {
                    if (graph[queue[j]][k] == 1 && visited[k] == 0) {
                        visited[k] = 1;
                        queue[count] = k;
                        count++;
                    }
                }
            }
            for (j = 0; j < count; j++) {
                for (k = 0; k < n; k++) {
                    distance[k] = -1;
                }
                distance[queue[j]] = 0;
                for (k = 0; k < count; k++) {
                    for (l = 0; l < n; l++) {
                        if (graph[queue[k]][l] == 1) {
                            if (distance[l] == -1) {
                                distance[l] = distance[queue[k]] + 1;
                            } else {
                                distance[l] = min(distance[l], distance[queue[k]] + 1);
                            }
                        }
                    }
                }
                for (k = 0; k < n; k++) {
                    if (distance[k] == -1) {
                        return -1;
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            queue[0] = i;
            count = 1;
            for (j = 0; j < count; j++) {
                for (k = 0; k < n; k++) {
                    if (graph[queue[j]][k] == 1 && visited[k] == 0) {
                        visited[k] = 1;
                        queue[count] = k;
                        count++;
                    }
                }
            }
            for (j = 0; j < count; j++) {
                for (k = 0; k < n; k++) {
                    distance[k] = -1;
                }
                distance[queue[j]] = 0;
                for (k = 0; k < count; k++) {
                    for (l = 0; l < n; l++) {
                        if (graph[queue[k]][l] == 1) {
                            if (distance[l] == -1) {
                                distance[l] = distance[queue[k]] + 1;
                            } else {
                                distance[l] = min(distance[l], distance[queue[k]] + 1);
                            }
                        }
                    }
                }
                for (k = 0; k < n; k++) {
                    if (distance[k] == -1) {
                        return -1;
                    }
                }
            }
        }
    }
}
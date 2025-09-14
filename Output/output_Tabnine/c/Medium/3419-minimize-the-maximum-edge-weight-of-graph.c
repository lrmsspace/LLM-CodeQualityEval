/*
 You are given two integers, n and threshold, as well as a directed weighted graph of n nodes numbered from 0 to n - 1. The graph is represented by a 2D integer array edges, where edges[i] = [Ai, Bi, Wi] indicates that there is an edge going from node Ai to node Bi with weight Wi.
 You have to remove some edges from this graph (possibly none), so that it satisfies the following conditions:
 Node 0 must be reachable from all other nodes.
 The maximum edge weight in the resulting graph is minimized.
 Each node has at most threshold outgoing edges.
 Return the minimum possible value of the maximum edge weight after removing the necessary edges. If it is impossible for all conditions to be satisfied, return -1.
 Example 1:
 Input: n = 5, edges = [[1,0,1],[2,0,2],[3,0,1],[4,3,1],[2,1,1]], threshold = 2
 Output: 1
 Explanation:
 Remove the edge 2 -> 0. The maximum weight among the remaining edges is 1.
 Example 2:
 Input: n = 5, edges = [[0,1,1],[0,2,2],[0,3,1],[0,4,1],[1,2,1],[1,4,1]], threshold = 1
 Output: -1
 Explanation: 
 It is impossible to reach node 0 from node 2.
 Example 3:
 Input: n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[3,4,2],[4,0,1]], threshold = 1
 Output: 2
 Explanation: 
 Remove the edges 1 -> 3 and 1 -> 4. The maximum weight among the remaining edges is 2.
 Example 4:
 Input: n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[4,0,1]], threshold = 1
 Output: -1
 Constraints:
 2 <= n <= 105
 1 <= threshold <= n - 1
 1 <= edges.length <= min(105, n * (n - 1) / 2).
 edges[i].length == 3
 0 <= Ai, Bi < n
 Ai != Bi
 1 <= Wi <= 106
 There may be multiple edges between a pair of nodes, but they must have unique weights.
*/

int minMaxWeight(int n, int** edges, int edgesSize, int* edgesColSize, int threshold) {
    int* graph[n];
    int degree[n];
    memset(degree, 0, sizeof(degree));

    // Create the adjacency list representation of the graph
    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        int weight = edges[i][2];

        graph[a] = realloc(graph[a], sizeof(int) * (degree[a] + 2));
        graph[a][degree[a]] = b;
        graph[a][degree[a] + 1] = weight;
        degree[a]++;

        graph[b] = realloc(graph[b], sizeof(int) * (degree[b] + 2));
        graph[b][degree[b]] = a;
        graph[b][degree[b] + 1] = weight;
        degree[b]++;
    }

    // Perform BFS to check if node 0 is reachable from all other nodes
    int visited[n];
    memset(visited, 0, sizeof(visited));
    visited[0] = 1;

    int queue[n];
    int front = 0, rear = 0;
    queue[rear++] = 0;

    while (front < rear) {
        int u = queue[front++];

        for (int i = 0; i < degree[u]; i += 2) {
            int v = graph[u][i];

            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (!visited[i]) {
            return -1; // It is impossible to reach node 0 from node i
        }
    }

    // Remove edges to minimize the maximum edge weight
    int maxWeight = 0;
    int removedEdges = 0;

    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        int weight = edges[i][2];

        if (degree[a] > threshold || degree[b] > threshold) {
            continue; // Do not remove edges connected to nodes with threshold outgoing edges
        }

        // Remove the edge and update the graph
        degree[a]--;
        degree[b]--;

        for (int j = 0; j < degree[a]; j += 2) {
            if (graph[a][j] == b) {
                memmove(&graph[a][j], &graph[a][j + 2], sizeof(int) * (degree[a] - j - 2));
                break;
            }
        }

        for (int j = 0; j < degree[b]; j += 2) {
            if (graph[b][j] == a) {
                memmove(&graph[b][j], &graph[b][j + 2], sizeof(int) * (degree[b] - j - 2));
                break;
            }
        }

        removedEdges++;
        maxWeight = weight;

        // Perform BFS again to check if node 0 is still reachable from all other nodes
        memset(visited, 0, sizeof(visited));
        visited[0] = 1;

        front = rear = 0;
        queue[rear++] = 0;

        while (front < rear) {
            int u = queue[front++];

            for (int j = 0; j < degree[u]; j += 2) {
                int v = graph[u][j];

                if (!visited[v]) {
                    visited[v] = 1;
                    queue[rear++] = v;
                }
            }
        }

        for (int j = 1; j < n; j++) {
            if (!visited[j]) {
                return -1; // It is impossible to reach node 0 from node j after removing the edge
            }
        }
    }

    if (removedEdges == 0) {
        return 0; // No edges need to be removed
    }

    return maxWeight;
}
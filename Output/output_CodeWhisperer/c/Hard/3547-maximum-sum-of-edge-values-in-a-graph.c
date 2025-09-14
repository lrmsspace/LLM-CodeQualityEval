/*
 You are given an undirected connected graph of n nodes, numbered from 0 to n - 1. Each node is connected to at most 2 other nodes.
 The graph consists of m edges, represented by a 2D array edges, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi.
 You have to assign a unique value from 1 to n to each node. The value of an edge will be the product of the values assigned to the two nodes it connects.
 Your score is the sum of the values of all edges in the graph.
 Return the maximum score you can achieve.
 Example 1:
 Input: n = 4, edges = [[0,1],[1,2],[2,3]]
 Output: 23
 Explanation:
 The diagram above illustrates an optimal assignment of values to nodes. The sum of the values of the edges is: (1 * 3) + (3 * 4) + (4 * 2) = 23.
 Example 2:
 Input: n = 6, edges = [[0,3],[4,5],[2,0],[1,3],[2,4],[1,5]]
 Output: 82
 Explanation:
 The diagram above illustrates an optimal assignment of values to nodes. The sum of the values of the edges is: (1 * 2) + (2 * 4) + (4 * 6) + (6 * 5) + (5 * 3) + (3 * 1) = 82.
 Constraints:
 1 <= n <= 5 * 104
 m == edges.length
 1 <= m <= n
 edges[i].length == 2
 0 <= ai, bi < n
 ai != bi
 There are no repeated edges.
 The graph is connected.
 Each node is connected to at most 2 other nodes.
*/

long long maxScore(int n, int** edges, int edgesSize, int* edgesColSize) {
    int i, j, k;
    long long max = 0;
    int* values = (int*)malloc(n * sizeof(int));
    int* visited = (int*)malloc(n * sizeof(int));
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    
    for (i = 0; i < n; i++) {
        values[i] = 1;
        visited[i] = 0;
    }
    
    for (i = 0; i < edgesSize; i++) {
        for (j = 0; j < 2; j++) {
            if (values[edges[i][j]] != 1) {
                values[edges[i][j]] = 1;
                visited[edges[i][j]] = 1;
                queue[rear++] = edges[i][j];
            }
        }
    }
    
    while (front < rear) {
        int node = queue[front++];
        for (i = 0; i < edgesSize; i++) {
            for (j = 0; j < 2; j++) {
                if (edges[i][j] == node) {
                    int otherNode = edges[i][1 - j];
                    if (!visited[otherNode]) {
                        visited[otherNode] = 1;
                        queue[rear++] = otherNode;
                        values[otherNode] = values[node] + 1;
                    }
                }
            }
        }
    }
    
    for (i = 0; i < edgesSize; i++) {
        long long score = (long long)(values[edges[i][0]] * values[edges[i][1]]) * (edges[i][0] + edges[i][1]);
        if (score > max) {
            max = score;
        }
    }
    
    free(values);
    free(visited);
    free(queue);
    
    return max / 2;    
}
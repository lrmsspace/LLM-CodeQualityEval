/**https://leetcode.com/problems/critical-connections-in-a-network/ */
//There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
//A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
//Return all critical connections in the network in any order.
// 
//Example 1:
//Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
//Output: [[1,3]]
//Explanation: [[3,1]] is also accepted.
//Example 2:
//Input: n = 2, connections = [[0,1]]
//Output: [[0,1]]
// 
//Constraints:
//	2 <= n <= 105
//	n - 1 <= connections.length <= 105
//	0 <= ai, bi <= n - 1
//	ai != bi
//	There are no repeated connections.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */ 
typedef struct {
    int u, v;
} Edge;

int time = 0;

void dfs(int u, int parent, int* disc, int* low, int* visited, Edge* edges, int** graph, int* graphSize, int* returnSize, int** result) {
    visited[u] = 1;
    disc[u] = low[u] = ++time;

    for (int i = 0; i < graphSize[u]; i++) {
        int v = graph[u][i];
        
        if (v == parent) continue;
        
        if (!visited[v]) {
            dfs(v, u, disc, low, visited, edges, graph, graphSize, returnSize, result);
            low[u] = (low[u] < low[v]) ? low[u] : low[v];
            
            if (low[v] > disc[u]) {
                (*result)[*returnSize] = (int *)malloc(2 * sizeof(int));
                (*result)[*returnSize][0] = u;
                (*result)[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(connectionsSize * sizeof(int));
    int** result = (int **)malloc(connectionsSize * sizeof(int *));
    
    int* disc = (int *)malloc(n * sizeof(int));
    int* low = (int *)malloc(n * sizeof(int));
    int* visited = (int *)calloc(n, sizeof(int));

    int** graph = (int **)malloc(n * sizeof(int *));
    int* graphSize = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, disc, low, visited, (Edge *)connections, graph, graphSize, returnSize, result);
        }
    }

    free(disc);
    free(low);
    free(visited);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(graphSize);

    return result;
}


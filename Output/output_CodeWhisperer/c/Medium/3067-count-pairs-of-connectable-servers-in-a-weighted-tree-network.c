/*
 You are given an unrooted weighted tree with n vertices representing servers numbered from 0 to n - 1, an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional edge between vertices ai and bi of weight weighti. You are also given an integer signalSpeed.
 Two servers a and b are connectable through a server c if:
 a < b, a != c and b != c.
 The distance from c to a is divisible by signalSpeed.
 The distance from c to b is divisible by signalSpeed.
 The path from c to b and the path from c to a do not share any edges.
 Return an integer array count of length n where count[i] is the number of server pairs that are connectable through the server i.
 Example 1:
 Input: edges = [[0,1,1],[1,2,5],[2,3,13],[3,4,9],[4,5,2]], signalSpeed = 1
 Output: [0,4,6,6,4,0]
 Explanation: Since signalSpeed is 1, count[c] is equal to the number of pairs of paths that start at c and do not share any edges.
 In the case of the given path graph, count[c] is equal to the number of servers to the left of c multiplied by the servers to the right of c.
 Example 2:
 Input: edges = [[0,6,3],[6,5,3],[0,3,1],[3,2,7],[3,1,6],[3,4,2]], signalSpeed = 3
 Output: [2,0,0,0,0,0,2]
 Explanation: Through server 0, there are 2 pairs of connectable servers: (4, 5) and (4, 6).
 Through server 6, there are 2 pairs of connectable servers: (4, 5) and (0, 5).
 It can be shown that no two servers are connectable through servers other than 0 and 6.
 Constraints:
 2 <= n <= 1000
 edges.length == n - 1
 edges[i].length == 3
 0 <= ai, bi < n
 edges[i] = [ai, bi, weighti]
 1 <= weighti <= 106
 1 <= signalSpeed <= 106
 The input is generated such that edges represents a valid tree.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countPairsOfConnectableServers(int** edges, int edgesSize, int* edgesColSize, int signalSpeed, int* returnSize) {
    // Initialize adjacency list
    int n = edgesSize + 1;
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));
    
    // Count number of neighbors for each vertex
    for(int i = 0; i < edgesSize; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }
    
    // Allocate memory for adjacency lists
    for(int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * 3 * sizeof(int));
        adjSize[i] = 0;
    }
    
    // Build adjacency list
    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        adj[u][adjSize[u]*3] = v;
        adj[u][adjSize[u]*3+1] = w;
        adj[u][adjSize[u]*3+2] = i;
        adjSize[u]++;
        
        adj[v][adjSize[v]*3] = u;
        adj[v][adjSize[v]*3+1] = w;
        adj[v][adjSize[v]*3+2] = i;
        adjSize[v]++;
    }
    
    *returnSize = n;
    int* result = (int*)calloc(n, sizeof(int));
    
    // For each vertex as center
    for(int center = 0; center < n; center++) {
        int* count = (int*)calloc(adjSize[center], sizeof(int));
        
        // DFS from each neighbor
        for(int i = 0; i < adjSize[center]; i++) {
            int next = adj[center][i*3];
            int weight = adj[center][i*3+1];
            int edgeId = adj[center][i*3+2];
            
            int* visited = (int*)calloc(edgesSize, sizeof(int));
            visited[edgeId] = 1;
            
            // DFS to count nodes with valid distance
            int dfs(int curr, int parent, int dist) {
                int cnt = (dist % signalSpeed == 0);
                for(int j = 0; j < adjSize[curr]; j++) {
                    int v = adj[curr][j*3];
                    int w = adj[curr][j*3+1];
                    int e = adj[curr][j*3+2];
                    if(v != parent && !visited[e]) {
                        visited[e] = 1;
                        cnt += dfs(v, curr, dist + w);
                    }
                }
                return cnt;
            }
            
            count[i] = dfs(next, center, weight);
            free(visited);
        }
        
        // Calculate pairs
        for(int i = 0; i < adjSize[center]; i++) {
            for(int j = i+1; j < adjSize[center]; j++) {
                result[center] += count[i] * count[j];
            }
        }
        
        free(count);
    }
    
    // Free memory
    for(int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSize);
    
    return result;
}    
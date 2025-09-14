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
    // Sort edges by weight
    for(int i = 0; i < edgesSize-1; i++) {
        for(int j = 0; j < edgesSize-i-1; j++) {
            if(edges[j][2] > edges[j+1][2]) {
                int temp0 = edges[j][0];
                int temp1 = edges[j][1]; 
                int temp2 = edges[j][2];
                edges[j][0] = edges[j+1][0];
                edges[j][1] = edges[j+1][1];
                edges[j][2] = edges[j+1][2];
                edges[j+1][0] = temp0;
                edges[j+1][1] = temp1;
                edges[j+1][2] = temp2;
            }
        }
    }
    
    // Try each weight as maximum allowed weight
    for(int maxWeight = edges[0][2]; maxWeight <= edges[edgesSize-1][2]; maxWeight++) {
        // Count outgoing edges for each node
        int* outDegree = (int*)calloc(n, sizeof(int));
        
        // Build adjacency list with edges <= maxWeight
        int** adj = (int**)malloc(n * sizeof(int*));
        for(int i = 0; i < n; i++) {
            adj[i] = (int*)malloc(n * sizeof(int));
            for(int j = 0; j < n; j++) {
                adj[i][j] = 0;
            }
        }
        
        for(int i = 0; i < edgesSize; i++) {
            if(edges[i][2] <= maxWeight) {
                int from = edges[i][0];
                int to = edges[i][1];
                if(outDegree[from] < threshold) {
                    adj[from][to] = 1;
                    outDegree[from]++;
                }
            }
        }
        
        // Check if node 0 is reachable from all nodes using DFS
        int* visited = (int*)calloc(n, sizeof(int));
        int valid = 1;
        
        // DFS to mark nodes that can reach 0
        void dfs(int node) {
            visited[node] = 1;
            for(int i = 0; i < n; i++) {
                if(adj[node][i] && !visited[i]) {
                    dfs(i);
                }
            }
        }
        
        // Start DFS from node 0 to mark reachable nodes
        dfs(0);
        
        // Check if all nodes can reach 0 by reversing edges
        int** revAdj = (int**)malloc(n * sizeof(int*));
        for(int i = 0; i < n; i++) {
            revAdj[i] = (int*)malloc(n * sizeof(int));
            for(int j = 0; j < n; j++) {
                revAdj[i][j] = adj[j][i];
            }
        }
        
        // Reset visited array
        for(int i = 0; i < n; i++) {
            visited[i] = 0;
        }
        
        // DFS from 0 on reversed graph
        void dfsRev(int node) {
            visited[node] = 1;
            for(int i = 0; i < n; i++) {
                if(revAdj[node][i] && !visited[i]) {
                    dfsRev(i);
                }
            }
        }
        
        dfsRev(0);
        
        // Check if all nodes were visited
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                valid = 0;
                break;
            }
        }
        
        // Free memory
        free(outDegree);
        free(visited);
        for(int i = 0; i < n; i++) {
            free(adj[i]);
            free(revAdj[i]);
        }
        free(adj);
        free(revAdj);
        
        if(valid) {
            return maxWeight;
        }
    }
    
    return -1;
}    
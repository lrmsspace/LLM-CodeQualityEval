/**https://leetcode.com/problems/shortest-path-with-alternating-colors/ */
//You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.
//You are given two arrays redEdges and blueEdges where:
//	redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
//	blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
//Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
// 
//Example 1:
//Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
//Output: [0,1,-1]
//Example 2:
//Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
//Output: [0,1,-1]
// 
//Constraints:
//	1 <= n <= 100
//	0 <= redEdges.length, blueEdges.length <= 400
//	redEdges[i].length == blueEdges[j].length == 2
//	0 <= ai, bi, uj, vj < n
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestAlternatingPaths(int n, int** redEdges, int redEdgesSize, int* redEdgesColSize, int** blueEdges, int blueEdgesSize, int* blueEdgesColSize, int* returnSize) {
    // Create adjacency lists for red and blue edges
    int** redAdjList = (int**)calloc(n, sizeof(int*));
    int** blueAdjList = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        redAdjList[i] = (int*)calloc(n, sizeof(int));
        blueAdjList[i] = (int*)calloc(n, sizeof(int));
    }
    
    for (int i = 0; i < redEdgesSize; i++) {
        redAdjList[redEdges[i][0]][redEdges[i][1]] = 1;
    }
    
    for (int i = 0; i < blueEdgesSize; i++) {
        blueAdjList[blueEdges[i][0]][blueEdges[i][1]] = 1;
    }
    
    // Initialize distance array and visited array
    int* dist = (int*)calloc(n, sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    
    // Initialize queue and enqueue node 0
    int* queue = (int*)calloc(n, sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = 0;
    dist[0] = 0;
    
    // Perform BFS
    while (front < rear) {
        int u = queue[front++];
        visited[u] = 1;
        
        if (u == n - 1) {
            break;
        }
        
        if (dist[u] % 2 == 0) {
            for (int v = 0; v < n; v++) {
                if (blueAdjList[u][v] &&!visited[v]) {
                    queue[rear++] = v;
                    dist[v] = dist[u] + 1;
                }
            }
        } else {
            for (int v = 0; v < n; v++) {
                if (redAdjList[u][v] &&!visited[v]) {
                    queue[rear++] = v;
                    dist[v] = dist[u] + 1;
                }
            }
        }
    }
    
    // Return the shortest path lengths
    *returnSize = n;
    int* result = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = dist[i] == INT_MAX? -1 : dist[i];
    }
    
    free(dist);
    free(visited);
    free(queue);
    
    for (int i = 0; i < n; i++) {
        free(redAdjList[i]);
        free(blueAdjList[i]);
    }
    
    free(redAdjList);
    free(blueAdjList);
    
    return result;
}
/**https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/ */
//Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
//Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
//Note that you can return the indices of the edges in any order.
// 
//Example 1:
//Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
//Output: [[0,1],[2,3,4,5]]
//Explanation: The figure above describes the graph.
//The following figure shows all the possible MSTs:
//Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
//The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.
//Example 2:
//Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
//Output: [[],[0,1,2,3]]
//Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
// 
//Constraints:
//	2 <= n <= 100
//	1 <= edges.length <= min(200, n * (n - 1) / 2)
//	edges[i].length == 3
//	0 <= ai < bi < n
//	1 <= weighti <= 1000
//	All pairs (ai, bi) are distinct.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findCriticalAndPseudoCriticalEdges(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize, int** returnColumnSizes) {
    // Your implementation here
    // Return an array of arrays of size *returnSize.
    // The sizes of the arrays are returned as *returnColumnSizes array.
    // Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
    
    // Step 1: Build adjacency list representation of the graph
    int** adjList = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        adjList[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = 0;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adjList[u][v] = weight;
        adjList[v][u] = weight;
    }
    
    // Step 2: Calculate minimum spanning tree (MST) using Prim's algorithm
    int* parent = (int*)malloc(n * sizeof(int));
    int* key = (int*)malloc(n * sizeof(int));
    bool* visited = (bool*)malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        key[i] = INT_MAX;
        visited[i] = false;
    }
    key[0] = 0;
    for (int count = 0; count < n - 1; count++) {
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }
        visited[minIndex] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && adjList[minIndex][v] && adjList[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = adjList[minIndex][v];
            }
        }
    }
    
    // Step 3: Find critical and pseudo-critical edges
    int** criticalEdges = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        criticalEdges[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = 0;
    }
    int** pseudoCriticalEdges = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        pseudoCriticalEdges[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = 0;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        int parentU = find(parent, u);
        int parentV = find(parent, v);


        // Check if edge (u, v) is a critical edge
        if (parentU!= parentV) {
            bool isCritical = true;
            for (int j = 0; j < n; j++) {
                if (j!= u && j!= v && find(parent, j) == parentU) {
                    isCritical = false;
                    break;
                }
            }
            if (isCritical) {
                criticalEdges[u][(*returnColumnSizes)[u]++] = i;
                criticalEdges[v][(*returnColumnSizes)[v]++] = i;
            } else {
                pseudoCriticalEdges[u][(*returnColumnSizes)[u]++] = i;
                pseudoCriticalEdges[v][(*returnColumnSizes)[v]++] = i;
            }
        }
    }
    
    // Step 4: Sort critical and pseudo-critical edges
    for (int i = 0; i < n; i++) {
        qsort(criticalEdges[i], (*returnColumnSizes)[i], sizeof(int), compare);
        qsort(pseudoCriticalEdges[i], (*returnColumnSizes)[i], sizeof(int), compare);
    }
    
    // Step 5: Return the result
    *returnSize = 2;
    int** result = (int**)malloc(2 * sizeof(int*));
    result[0] = (int*)malloc((*returnSize) * (*returnColumnSizes)[0] * sizeof(int));
    result[1] = (int*)malloc((*returnSize) * (*returnColumnSizes)[1] * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (*returnColumnSizes)[i]; j++) {
            result[0][i * (*returnColumnSizes)[0] + j] = criticalEdges[i][j];
            result[1][i * (*returnColumnSizes)[1] + j] = pseudoCriticalEdges[i][j];
        }
    }
    
    // Step 6: Free the allocated memory
    free(adjList);
    free(parent);
    free(key);
    free(visited);
    for (int i = 0; i < n; i++) {
        free(criticalEdges[i]);
        free(pseudoCriticalEdges[i]);
    }
    free(criticalEdges);
    free(pseudoCriticalEdges);
    
    return result;
}
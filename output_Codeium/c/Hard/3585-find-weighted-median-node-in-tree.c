/*
 You are given an integer n and an undirected, weighted tree rooted at node 0 with n nodes numbered from 0 to n - 1. This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, wi] indicates an edge from node ui to vi with weight wi.
 The weighted median node is defined as the first node x on the path from ui to vi such that the sum of edge weights from ui to x is greater than or equal to half of the total path weight.
 You are given a 2D integer array queries. For each queries[j] = [uj, vj], determine the weighted median node along the path from uj to vj.
 Return an array ans, where ans[j] is the node index of the weighted median for queries[j].
 Example 1:
 Input: n = 2, edges = [[0,1,7]], queries = [[1,0],[0,1]]
 Output: [0,1]
 Explanation:
 Query
 Path
 Edge
 			Weights
 Total
 			Path
 			Weight
 Half
 Explanation
 Answer
 [1, 0]
 1 → 0
 [7]
 7
 3.5
 Sum from 1 → 0 = 7 >= 3.5, median is node 0.
 0
 [0, 1]
 0 → 1
 [7]
 7
 3.5
 Sum from 0 → 1 = 7 >= 3.5, median is node 1.
 1
 Example 2:
 Input: n = 3, edges = [[0,1,2],[2,0,4]], queries = [[0,1],[2,0],[1,2]]
 Output: [1,0,2]
 Explanation:
 Query
 Path
 Edge
 			Weights
 Total
 			Path
 			Weight
 Half
 Explanation
 Answer
 [0, 1]
 0 → 1
 [2]
 2
 1
 Sum from 0 → 1 = 2 >= 1, median is node 1.
 1
 [2, 0]
 2 → 0
 [4]
 4
 2
 Sum from 2 → 0 = 4 >= 2, median is node 0.
 0
 [1, 2]
 1 → 0 → 2
 [2, 4]
 6
 3
 Sum from 1 → 0 = 2 < 3.
 			Sum from 1 → 2 = 2 + 4 = 6 >= 3, median is node 2.
 2
 Example 3:
 Input: n = 5, edges = [[0,1,2],[0,2,5],[1,3,1],[2,4,3]], queries = [[3,4],[1,2]]
 Output: [2,2]
 Explanation:
 Query
 Path
 Edge
 			Weights
 Total
 			Path
 			Weight
 Half
 Explanation
 Answer
 [3, 4]
 3 → 1 → 0 → 2 → 4
 [1, 2, 5, 3]
 11
 5.5
 Sum from 3 → 1 = 1 < 5.5.
 			Sum from 3 → 0 = 1 + 2 = 3 < 5.5.
 			Sum from 3 → 2 = 1 + 2 + 5 = 8 >= 5.5, median is node 2.
 2
 [1, 2]
 1 → 0 → 2
 [2, 5]
 7
 3.5
 Sum from 1 → 0 = 2 < 3.5.
 			Sum from 1 → 2 = 2 + 5 = 7 >= 3.5, median is node 2.
 2
 Constraints:
 2 <= n <= 105
 edges.length == n - 1
 edges[i] == [ui, vi, wi]
 0 <= ui, vi < n
 1 <= wi <= 109
 1 <= queries.length <= 105
 queries[j] == [uj, vj]
 0 <= uj, vj < n
 The input is generated such that edges represents a valid tree.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Helper function to perform DFS and calculate path weights
void dfs(int node, int parent, int* weight, int* pathWeight, int* parentArr, int** adjList, int* adjListSize) {
    parentArr[node] = parent;
    for (int i = 0; i < adjListSize[node]; i++) {
        int neighbor = adjList[node][i];
        if (neighbor != parent) {
            pathWeight[neighbor] = pathWeight[node] + weight[i];
            dfs(neighbor, node, weight, pathWeight, parentArr, adjList, adjListSize);
        }
    }
}

// Function to find the weighted median node for a single query
int findWeightedMedian(int u, int v, int* parentArr, int* pathWeight) {
    int totalWeight = pathWeight[v] - pathWeight[u];
    int halfWeight = totalWeight / 2;
    int current = v;
    while (pathWeight[current] - pathWeight[u] > halfWeight) {
        current = parentArr[current];
    }
    return current;
}

int* findMedian(int n, int** edges, int edgesSize, int* edgesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* result = (int*)malloc(queriesSize * sizeof(int));

    // Create adjacency list
    int** adjList = (int**)malloc(n * sizeof(int*));
    int* adjListSize = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjListSize[u]++;
        adjListSize[v]++;
    }
    for (int i = 0; i < n; i++) {
        adjList[i] = (int*)malloc(adjListSize[i] * sizeof(int));
        adjListSize[i] = 0; // reset to use for index tracking
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u][adjListSize[u]++] = v;
        adjList[v][adjListSize[v]++] = u;
    }

    // Perform DFS to calculate path weights
    int* weight = (int*)malloc(edgesSize * sizeof(int));
    int* pathWeight = (int*)calloc(n, sizeof(int));
    int* parentArr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        weight[i] = edges[i][2];
    }
    dfs(0, -1, weight, pathWeight, parentArr, adjList, adjListSize);

    // Find weighted median for each query
    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0];
        int v = queries[i][1];
        result[i] = findWeightedMedian(u, v, parentArr, pathWeight);
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(adjList[i]);
    }
    free(adjList);
    free(weight);
    free(pathWeight);
    free(parentArr);
    return result;


}
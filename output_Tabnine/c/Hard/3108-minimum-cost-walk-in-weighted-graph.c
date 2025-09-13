/*
 There is an undirected weighted graph with n vertices labeled from 0 to n - 1.
 You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.
 A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.
 The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.
 You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.
 Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.
 Example 1:
 Input: n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]
 Output: [1,-1]
 Explanation:
 To achieve the cost of 1 in the first query, we need to move on the following edges: 0->1 (weight 7), 1->2 (weight 1), 2->1 (weight 1), 1->3 (weight 7).
 In the second query, there is no walk between nodes 3 and 4, so the answer is -1.
 Example 2:
 Input: n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]
 Output: [0]
 Explanation:
 To achieve the cost of 0 in the first query, we need to move on the following edges: 1->2 (weight 1), 2->1 (weight 6), 1->2 (weight 1).
 Constraints:
 2 <= n <= 105
 0 <= edges.length <= 105
 edges[i].length == 3
 0 <= ui, vi <= n - 1
 ui != vi
 0 <= wi <= 105
 1 <= query.length <= 105
 query[i].length == 2
 0 <= si, ti <= n - 1
 si != ti
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define INF INT_MAX

typedef struct {
    int u;
    int v;
    int weight;
} Edge;

typedef struct {
    int vertex;
    int cost;
} Node;

int compare(const void* a, const void* b) {
    return ((Node*)a)->cost - ((Node*)b)->cost;
}

int* minimumCost(int n, int** edges, int edgesSize, int* edgesColSize, int** query, int querySize, int* queryColSize, int* returnSize) {
    int* answer = (int*)malloc(querySize * sizeof(int));
    *returnSize = querySize;

    // Create adjacency list
    Edge** adjList = (Edge**)malloc(n * sizeof(Edge*));
    int* degree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        Edge* newEdge = (Edge*)malloc(sizeof(Edge));
        newEdge->u = u;
        newEdge->v = v;
        newEdge->weight = weight;

        degree[u]++;
        degree[v]++;

        newEdge->next = adjList[u];
        adjList[u] = newEdge;

        newEdge = (Edge*)malloc(sizeof(Edge));
        newEdge->u = v;
        newEdge->v = u;
        newEdge->weight = weight;

        newEdge->next = adjList[v];
        adjList[v] = newEdge;
    }

    // Initialize dp array
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
        dp[i][i] = 0;
    }

    // Dijkstra's algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    // Calculate minimum cost for each query
    for (int i = 0; i < querySize; i++) {
        int si = query[i][0];
        int ti = query[i][1];

        if (dp[si][ti] == INF) {
            answer[i] = -1;
        } else {
            answer[i] = dp[si][ti];
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        Edge* edge = adjList[i];
        while (edge != NULL) {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
        free(adjList[i]);
        free(dp[i]);
    }
    free(adjList);
    free(degree);
    free(dp);

    return answer;
}


/*
 There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ui, vi, wi] indicates that there is an edge between nodes ui and vi with weight wi in the tree.
 You are also given a 2D integer array queries of length m, where queries[i] = [ai, bi]. For each query, find the minimum number of operations required to make the weight of every edge on the path from ai to bi equal. In one operation, you can choose any edge of the tree and change its weight to any value.
 Note that:
 Queries are independent of each other, meaning that the tree returns to its initial state on each new query.
 The path from ai to bi is a sequence of distinct nodes starting with node ai and ending with node bi such that every two adjacent nodes in the sequence share an edge in the tree.
 Return an array answer of length m where answer[i] is the answer to the ith query.
 Example 1:
 Input: n = 7, edges = [[0,1,1],[1,2,1],[2,3,1],[3,4,2],[4,5,2],[5,6,2]], queries = [[0,3],[3,6],[2,6],[0,6]]
 Output: [0,0,1,3]
 Explanation: In the first query, all the edges in the path from 0 to 3 have a weight of 1. Hence, the answer is 0.
 In the second query, all the edges in the path from 3 to 6 have a weight of 2. Hence, the answer is 0.
 In the third query, we change the weight of edge [2,3] to 2. After this operation, all the edges in the path from 2 to 6 have a weight of 2. Hence, the answer is 1.
 In the fourth query, we change the weights of edges [0,1], [1,2] and [2,3] to 2. After these operations, all the edges in the path from 0 to 6 have a weight of 2. Hence, the answer is 3.
 For each queries[i], it can be shown that answer[i] is the minimum number of operations needed to equalize all the edge weights in the path from ai to bi.
 Example 2:
 Input: n = 8, edges = [[1,2,6],[1,3,4],[2,4,6],[2,5,3],[3,6,6],[3,0,8],[7,0,2]], queries = [[4,6],[0,4],[6,5],[7,4]]
 Output: [1,2,2,3]
 Explanation: In the first query, we change the weight of edge [1,3] to 6. After this operation, all the edges in the path from 4 to 6 have a weight of 6. Hence, the answer is 1.
 In the second query, we change the weight of edges [0,3] and [3,1] to 6. After these operations, all the edges in the path from 0 to 4 have a weight of 6. Hence, the answer is 2.
 In the third query, we change the weight of edges [1,3] and [5,2] to 6. After these operations, all the edges in the path from 6 to 5 have a weight of 6. Hence, the answer is 2.
 In the fourth query, we change the weights of edges [0,7], [0,3] and [1,3] to 6. After these operations, all the edges in the path from 7 to 4 have a weight of 6. Hence, the answer is 3.
 For each queries[i], it can be shown that answer[i] is the minimum number of operations needed to equalize all the edge weights in the path from ai to bi.
 Constraints:
 1 <= n <= 104
 edges.length == n - 1
 edges[i].length == 3
 0 <= ui, vi < n
 1 <= wi <= 26
 The input is generated such that edges represents a valid tree.
 1 <= queries.length == m <= 2 * 104
 queries[i].length == 2
 0 <= ai, bi < n
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_N 10001
#define MAX_W 27
#define MAX_LOG 14  // log2(10^4)

// 存储边的结构
typedef struct Edge {
    int to;
    int weight;
} Edge;

// 存储节点的邻接表
typedef struct {
    Edge* edges;
    int size;
    int capacity;
} AdjList;

// 计算两个数组的差值
void arrayDiff(int* arr1, int* arr2, int* result, int size) {
    for (int i = 1; i <= 26; i++) {
        result[i] = arr1[i] - arr2[i];
    }
}

// DFS预处理，计算深度和父节点信息
void dfs(AdjList* graph, int node, int parent, int depth, 
         int* depths, int** parents, int** counts, 
         int (*edgeWeights)[MAX_N][MAX_W]) {
    depths[node] = depth;
    parents[node][0] = parent;
    
    for (int i = 0; i < graph[node].size; i++) {
        Edge next = graph[node].edges[i];
        if (next.to != parent) {
            // 更新到当前节点的路径上各权重的计数
            for (int w = 1; w <= 26; w++) {
                edgeWeights[next.to][0][w] = edgeWeights[node][0][w];
            }
            edgeWeights[next.to][0][next.weight]++;
            
            dfs(graph, next.to, node, depth + 1, depths, parents, counts, edgeWeights);
        }
    }
}

int* minOperationsQueries(int n, int** edges, int edgesSize, int* edgesColSize, 
                         int** queries, int queriesSize, int* queriesColSize, 
                         int* returnSize) {
    // 初始化邻接表
    AdjList* graph = (AdjList*)calloc(n, sizeof(AdjList));
    for (int i = 0; i < n; i++) {
        graph[i].edges = (Edge*)malloc(sizeof(Edge) * n);
        graph[i].size = 0;
        graph[i].capacity = n;
    }
    
    // 建图
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        graph[u].edges[graph[u].size++] = (Edge){v, w};
            graph[v].edges[graph[v].size++] = (Edge){u, w};
    }
    
    // 初始化数组
    int* depths = (int*)calloc(n, sizeof(int));
    int** parents = (int**)malloc(n * sizeof(int*));
    int (*edgeWeights)[MAX_N][MAX_W] = calloc(n, sizeof(*edgeWeights));
    
    for (int i = 0; i < n; i++) {
        parents[i] = (int*)malloc(MAX_LOG * sizeof(int));
        for (int j = 0; j < MAX_LOG; j++) {
            parents[i][j] = -1;
        }
    }
    
    // DFS预处理
    dfs(graph, 0, -1, 0, depths, parents, NULL, edgeWeights);
    
    // 处理父节点数组
    for (int j = 1; j < MAX_LOG; j++) {
        for (int i = 0; i < n; i++) {
            if (parents[i][j-1] != -1) {
                parents[i][j] = parents[parents[i][j-1]][j-1];
            }
        }
    }
    
    // 处理查询
    int* result = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    
    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0], v = queries[i][1];
        int lca = u;
        
        // 找LCA
        if (depths[u] < depths[v]) {
            int temp = u;
            u = v;
            v = temp;
        }
        
        int diff = depths[u] - depths[v];
        for (int j = 0; diff > 0; j++) {
            if (diff & 1) u = parents[u][j];
            diff >>= 1;
        }
        
        if (u != v) {
            for (int j = MAX_LOG-1; j >= 0; j--) {
                if (parents[u][j] != -1 && parents[u][j] != parents[v][j]) {
                    u = parents[u][j];
                    v = parents[v][j];
                }
            }
            lca = parents[u][0];
        }
        
        // 计算路径上的权重
        int pathLen = depths[queries[i][0]] + depths[queries[i][1]] - 2 * depths[lca];
        int weightCount[MAX_W] = {0};
        arrayDiff(edgeWeights[queries[i][0]][0], edgeWeights[lca][0], weightCount, MAX_W);
        
        int temp[MAX_W] = {0};
        arrayDiff(edgeWeights[queries[i][1]][0], edgeWeights[lca][0], temp, MAX_W);
        for (int w = 1; w <= 26; w++) {
            weightCount[w] += temp[w];
        }
        
        // 计算最小操作次数
        int maxCount = 0;
        for (int w = 1; w <= 26; w++) {
            if (weightCount[w] > maxCount) {
                maxCount = weightCount[w];
            }
        }
        result[i] = pathLen - maxCount;
    }
    
    // 释放内存
    for (int i = 0; i < n; i++) {
        free(graph[i].edges);
        free(parents[i]);
    }
    free(graph);
    free(parents);
    free(depths);
    free(edgeWeights);
    
    return result;
}

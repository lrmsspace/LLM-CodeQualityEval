/*
 There is a simple directed graph with n nodes labeled from 0 to n - 1. The graph would form a tree if its edges were bi-directional.
 You are given an integer n and a 2D integer array edges, where edges[i] = [ui, vi] represents a directed edge going from node ui to node vi.
 An edge reversal changes the direction of an edge, i.e., a directed edge going from node ui to node vi becomes a directed edge going from node vi to node ui.
 For every node i in the range [0, n - 1], your task is to independently calculate the minimum number of edge reversals required so it is possible to reach any other node starting from node i through a sequence of directed edges.
 Return an integer array answer, where answer[i] is the  minimum number of edge reversals required so it is possible to reach any other node starting from node i through a sequence of directed edges.
 Example 1:
 Input: n = 4, edges = [[2,0],[2,1],[1,3]]
 Output: [1,1,0,2]
 Explanation: The image above shows the graph formed by the edges.
 For node 0: after reversing the edge [2,0], it is possible to reach any other node starting from node 0.
 So, answer[0] = 1.
 For node 1: after reversing the edge [2,1], it is possible to reach any other node starting from node 1.
 So, answer[1] = 1.
 For node 2: it is already possible to reach any other node starting from node 2.
 So, answer[2] = 0.
 For node 3: after reversing the edges [1,3] and [2,1], it is possible to reach any other node starting from node 3.
 So, answer[3] = 2.
 Example 2:
 Input: n = 3, edges = [[1,2],[2,0]]
 Output: [2,0,1]
 Explanation: The image above shows the graph formed by the edges.
 For node 0: after reversing the edges [2,0] and [1,2], it is possible to reach any other node starting from node 0.
 So, answer[0] = 2.
 For node 1: it is already possible to reach any other node starting from node 1.
 So, answer[1] = 0.
 For node 2: after reversing the edge [1, 2], it is possible to reach any other node starting from node 2.
 So, answer[2] = 1.
 Constraints:
 2 <= n <= 105
 edges.length == n - 1
 edges[i].length == 2
 0 <= ui == edges[i][0] < n
 0 <= vi == edges[i][1] < n
 ui != vi
 The input is generated such that if the edges were bi-directional, the graph would be a tree.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 定义图的节点结构
typedef struct Node {
    int to;
    int isReverse;  // 1表示需要反转，0表示不需要
    struct Node* next;
} Node;

// 添加边到邻接表
void addEdge(Node** graph, int from, int to, int isReverse) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->to = to;
    newNode->isReverse = isReverse;
    newNode->next = graph[from];
    graph[from] = newNode;
}

// 第一次DFS：计算从节点start到其他节点需要的最小反转次数
void dfs1(Node** graph, int curr, int parent, int* count, bool* visited) {
    visited[curr] = true;
    
    for (Node* edge = graph[curr]; edge != NULL; edge = edge->next) {
        int next = edge->to;
        if (!visited[next]) {
            count[next] = count[curr] + edge->isReverse;
            dfs1(graph, next, curr, count, visited);
        }
    }
}

// 第二次DFS：计算从其他节点出发时的反转次数变化
void dfs2(Node** graph, int curr, int parent, int* count, bool* visited) {
    visited[curr] = true;
    
    for (Node* edge = graph[curr]; edge != NULL; edge = edge->next) {
        int next = edge->to;
        if (!visited[next]) {
            // 如果当前边需要反转，那么从next出发时需要的反转数会减1
            // 如果当前边不需要反转，那么从next出发时需要的反转数会加1
            count[next] = count[curr] + (edge->isReverse ? -1 : 1);
            dfs2(graph, next, curr, count, visited);
        }
    }
}

int* minEdgeReversals(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    // 创建邻接表
    Node** graph = (Node**)calloc(n, sizeof(Node*));
    
    // 构建图
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        // 正向边不需要反转(isReverse=0)，反向边需要反转(isReverse=1)
        addEdge(graph, u, v, 0);
        addEdge(graph, v, u, 1);
    }
    
    // 分配结果数组
    int* result = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    
    // 第一次DFS：计算从节点0到其他节点的最小反转次数
    bool* visited = (bool*)calloc(n, sizeof(bool));
    result[0] = 0;
    dfs1(graph, 0, -1, result, visited);
    
    // 第二次DFS：计算其他节点作为起点的情况
    memset(visited, 0, n * sizeof(bool));
    dfs2(graph, 0, -1, result, visited);
    
    // 释放内存
    for (int i = 0; i < n; i++) {
        Node* curr = graph[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph);
    free(visited);
    
    return result;
}

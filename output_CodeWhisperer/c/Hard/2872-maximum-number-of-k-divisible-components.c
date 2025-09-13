/*
 There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
 You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.
 A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.
 Return the maximum number of components in any valid split.
 Example 1:
 Input: n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6
 Output: 2
 Explanation: We remove the edge connecting node 1 with 2. The resulting split is valid because:
 - The value of the component containing nodes 1 and 3 is values[1] + values[3] = 12.
 - The value of the component containing nodes 0, 2, and 4 is values[0] + values[2] + values[4] = 6.
 It can be shown that no other valid split has more than 2 connected components.
 Example 2:
 Input: n = 7, edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [3,0,6,1,5,2,1], k = 3
 Output: 3
 Explanation: We remove the edge connecting node 0 with 2, and the edge connecting node 0 with 1. The resulting split is valid because:
 - The value of the component containing node 0 is values[0] = 3.
 - The value of the component containing nodes 2, 5, and 6 is values[2] + values[5] + values[6] = 9.
 - The value of the component containing nodes 1, 3, and 4 is values[1] + values[3] + values[4] = 6.
 It can be shown that no other valid split has more than 3 connected components.
 Constraints:
 1 <= n <= 3 * 104
 edges.length == n - 1
 edges[i].length == 2
 0 <= ai, bi < n
 values.length == n
 0 <= values[i] <= 109
 1 <= k <= 109
 Sum of values is divisible by k.
 The input is generated such that edges represents a valid tree.
*/
#define MAX_N 30001

// 邻接表节点结构
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// 添加边到邻接表
void addEdge(Node** graph, int from, int to) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = to;
    newNode->next = graph[from];
    graph[from] = newNode;
}

// DFS函数，返回子树的和和可分割的组件数
long long dfs(Node** graph, int curr, int parent, int* values, int k, int* result) {
    long long sum = values[curr];  // 当前节点的值
    
    // 遍历所有子节点
    for (Node* edge = graph[curr]; edge != NULL; edge = edge->next) {
        int next = edge->val;
        if (next != parent) {
            // 递归处理子树
            long long subSum = dfs(graph, next, curr, values, k, result);
            sum += subSum;
        }
    }
    
    // 如果当前子树的和能被k整除，可以形成一个独立的组件
    if (sum % k == 0) {
        (*result)++;
        return 0;  // 返回0表示这个子树已经被分割出去
    }
    
    return sum;  // 返回子树的和
}

int maxKDivisibleComponents(int n, int** edges, int edgesSize, int* edgesColSize, int* values, int valuesSize, int k) {
    // 创建邻接表
    Node** graph = (Node**)calloc(n, sizeof(Node*));
    
    // 构建无向图
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }
    
    int result = 0;
    // 从根节点(0)开始DFS
    dfs(graph, 0, -1, values, k, &result);
    
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
    
    return result;
}

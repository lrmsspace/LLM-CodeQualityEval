/*
 There exists an undirected tree rooted at node 0 with n nodes labeled from 0 to n - 1. You are given a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given a 0-indexed array coins of size n where coins[i] indicates the number of coins in the vertex i, and an integer k.
 Starting from the root, you have to collect all the coins such that the coins at a node can only be collected if the coins of its ancestors have been already collected.
 Coins at nodei can be collected in one of the following ways:
 Collect all the coins, but you will get coins[i] - k points. If coins[i] - k is negative then you will lose abs(coins[i] - k) points.
 Collect all the coins, but you will get floor(coins[i] / 2) points. If this way is used, then for all the nodej present in the subtree of nodei, coins[j] will get reduced to floor(coins[j] / 2).
 Return the maximum points you can get after collecting the coins from all the tree nodes.
 Example 1:
 Input: edges = [[0,1],[1,2],[2,3]], coins = [10,10,3,3], k = 5
 Output: 11                        
 Explanation: 
 Collect all the coins from node 0 using the first way. Total points = 10 - 5 = 5.
 Collect all the coins from node 1 using the first way. Total points = 5 + (10 - 5) = 10.
 Collect all the coins from node 2 using the second way so coins left at node 3 will be floor(3 / 2) = 1. Total points = 10 + floor(3 / 2) = 11.
 Collect all the coins from node 3 using the second way. Total points = 11 + floor(1 / 2) = 11.
 It can be shown that the maximum points we can get after collecting coins from all the nodes is 11. 
 Example 2:
 Input: edges = [[0,1],[0,2]], coins = [8,4,4], k = 0
 Output: 16
 Explanation: 
 Coins will be collected from all the nodes using the first way. Therefore, total points = (8 - 0) + (4 - 0) + (4 - 0) = 16.
 Constraints:
 n == coins.length
 2 <= n <= 105
 0 <= coins[i] <= 104
 edges.length == n - 1
 0 <= edges[i][0], edges[i][1] < n
 0 <= k <= 104
*/


#define MAX_N 100001
#define MAX(a, b) ((a) > (b) ? (a) : (b))

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

// DFS函数，返回两种选择的最大值
// dp[node][0]: 选择减k的最大值
// dp[node][1]: 选择除2的最大值
void dfs(Node** graph, int node, int parent, int* coins, int k, long long dp[][2]) {
    long long take = coins[node] - k;  // 选择减k
    long long divide = coins[node] / 2; // 选择除2
    
    // 遍历所有子节点
    for (Node* curr = graph[node]; curr != NULL; curr = curr->next) {
        int child = curr->val;
        if (child == parent) continue;
        
        // 递归处理子节点
        dfs(graph, child, node, coins, k, dp);
        
        // 如果当前节点选择减k，子节点可以任选
        take += MAX(dp[child][0], dp[child][1]);
        
        // 如果当前节点选择除2，子节点的coins值都要除2
        // 注意：这里的coins[child]/2是在原来coins[child]/2的基础上再除2
        int newCoins = coins[child] / 2;
        coins[child] = newCoins;
        divide += dp[child][1];
    }
    
    dp[node][0] = take;
    dp[node][1] = divide;
}

int maximumPoints(int** edges, int edgesSize, int* edgesColSize, int* coins, int coinsSize, int k) {
    // 构建邻接表
    Node** graph = (Node**)calloc(coinsSize, sizeof(Node*));
    
    // 添加边
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }
    
    // 创建dp数组
    long long dp[MAX_N][2] = {0};
    
    // 保存原始coins数组
    int* originalCoins = (int*)malloc(coinsSize * sizeof(int));
    memcpy(originalCoins, coins, coinsSize * sizeof(int));
    
    // DFS求解
    dfs(graph, 0, -1, coins, k, dp);
    
    // 获取结果
    long long result = MAX(dp[0][0], dp[0][1]);
    
    // 释放内存
    for (int i = 0; i < coinsSize; i++) {
        Node* curr = graph[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph);
    free(originalCoins);
    
    return (int)result;
}

/*
 There is an undirected tree with n nodes labeled from 1 to n. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree.
 Return the number of valid paths in the tree.
 A path (a, b) is valid if there exists exactly one prime number among the node labels in the path from a to b.
 Note that:
 The path (a, b) is a sequence of distinct nodes starting with node a and ending with node b such that every two adjacent nodes in the sequence share an edge in the tree.
 Path (a, b) and path (b, a) are considered the same and counted only once.
 Example 1:
 Input: n = 5, edges = [[1,2],[1,3],[2,4],[2,5]]
 Output: 4
 Explanation: The pairs with exactly one prime number on the path between them are: 
 - (1, 2) since the path from 1 to 2 contains prime number 2. 
 - (1, 3) since the path from 1 to 3 contains prime number 3.
 - (1, 4) since the path from 1 to 4 contains prime number 2.
 - (2, 4) since the path from 2 to 4 contains prime number 2.
 It can be shown that there are only 4 valid paths.
 Example 2:
 Input: n = 6, edges = [[1,2],[1,3],[2,4],[3,5],[3,6]]
 Output: 6
 Explanation: The pairs with exactly one prime number on the path between them are: 
 - (1, 2) since the path from 1 to 2 contains prime number 2.
 - (1, 3) since the path from 1 to 3 contains prime number 3.
 - (1, 4) since the path from 1 to 4 contains prime number 2.
 - (1, 6) since the path from 1 to 6 contains prime number 3.
 - (2, 4) since the path from 2 to 4 contains prime number 2.
 - (3, 6) since the path from 3 to 6 contains prime number 3.
 It can be shown that there are only 6 valid paths.
 Constraints:
 1 <= n <= 105
 edges.length == n - 1
 edges[i].length == 2
 1 <= ui, vi <= n
 The input is generated such that edges represent a valid tree.
*/

#define MAX_N 100001

// 判断是否为质数
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// 用于存储图的邻接表节点
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// DFS处理函数
void dfs(int curr, int parent, Node** graph, bool* isPrimeArr, 
         long long* nonPrimeCount, long long* primeCount, long long* result) {
    // 当前节点的计数初始化为1（表示节点自身）
    long long currNonPrime = !isPrimeArr[curr];
    long long currPrime = isPrimeArr[curr];
    
    // 遍历所有邻接节点
    Node* neighbor = graph[curr];
    while (neighbor) {
        int next = neighbor->val;
        if (next != parent) {
            // 递归处理子节点
            dfs(next, curr, graph, isPrimeArr, nonPrimeCount, primeCount, result);
            
            // 更新结果：
            // 当前非质数节点与子树中的质数节点组成有效路径
            *result += currNonPrime * primeCount[next];
            // 当前质数节点与子树中的非质数节点组成有效路径
            *result += currPrime * nonPrimeCount[next];
            
            // 累加子树的计数
            currNonPrime += nonPrimeCount[next];
            currPrime += primeCount[next];
        }
        neighbor = neighbor->next;
    }
    
    // 保存当前节点的计数结果
    nonPrimeCount[curr] = currNonPrime;
    primeCount[curr] = currPrime;
}

long long countPaths(int n, int** edges, int edgesSize, int* edgesColSize) {
    // 创建并初始化邻接表
    Node** graph = (Node**)calloc(n + 1, sizeof(Node*));
    
    // 构建邻接表
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        // 添加边 u -> v
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = v;
        newNode->next = graph[u];
        graph[u] = newNode;
        
        // 添加边 v -> u
        newNode = (Node*)malloc(sizeof(Node));
        newNode->val = u;
        newNode->next = graph[v];
        graph[v] = newNode;
    }
    
    // 预处理每个节点是否为质数
    bool* isPrimeArr = (bool*)calloc(n + 1, sizeof(bool));
    for (int i = 1; i <= n; i++) {
        isPrimeArr[i] = isPrime(i);
    }
    
    // 用于存储每个节点子树中的质数和非质数节点数量
    long long* nonPrimeCount = (long long*)calloc(n + 1, sizeof(long long));
    long long* primeCount = (long long*)calloc(n + 1, sizeof(long long));
    
    long long result = 0;
    // 从节点1开始DFS
    dfs(1, 0, graph, isPrimeArr, nonPrimeCount, primeCount, &result);
    
    // 释放内存
    for (int i = 1; i <= n; i++) {
        Node* curr = graph[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph);
    free(isPrimeArr);
    free(nonPrimeCount);
    free(primeCount);
    
    return result;
}

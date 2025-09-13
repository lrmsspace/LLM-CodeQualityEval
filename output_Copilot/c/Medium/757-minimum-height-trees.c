/**https://leetcode.com/problems/minimum-height-trees/ */
//A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
//Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
//Return a list of all MHTs' root labels. You can return the answer in any order.
//The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
// 
//Example 1:
//Input: n = 4, edges = [[1,0],[1,2],[1,3]]
//Output: [1]
//Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
//Example 2:
//Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
//Output: [3,4]
// 
//Constraints:
//	1 <= n <= 2 * 104
//	edges.length == n - 1
//	0 <= ai, bi < n
//	ai != bi
//	All the pairs (ai, bi) are distinct.
//	The given input is guaranteed to be a tree and there will be no repeated edges.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    if (n == 1) {
        *returnSize = 1;
        int* ret = (int*)malloc(sizeof(int) * 1);
        ret[0] = 0;
        return ret;
    }
    int* indegree = (int*)malloc(sizeof(int) * n);
    int* ret = (int*)malloc(sizeof(int) * n);
    int retSize = 0;
    int** graph = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(sizeof(int) * n);
        indegree[i] = 0;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][v] = 1;
        graph[v][u] = 1;
        indegree[u]++;
        indegree[v]++;
    }
    int* queue = (int*)malloc(sizeof(int) * n);
    int front = 0;
    int rear = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 1) {
            queue[rear++] = i;
        }
    }
    while (rear - front > 0) {
        retSize = rear - front;
        for (int i = 0; i < retSize; i++) {
            int u = queue[front++];
            ret[i] = u;
            for (int v = 0; v < n; v++) {
                if (graph[u][v] == 1) {
                    indegree[v]--;
                    if (indegree[v] == 1) {
                        queue[rear++] = v;
                    }
                }
            }
        }
    }
    *returnSize = retSize;
    return ret;    
}
/**https://leetcode.com/problems/sum-of-distances-in-tree/ */
//There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
//You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.
// 
//Example 1:
//Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
//Output: [8,12,6,10,10,10]
//Explanation: The tree is shown above.
//We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
//equals 1 + 1 + 2 + 2 + 2 = 8.
//Hence, answer[0] = 8, and so on.
//Example 2:
//Input: n = 1, edges = []
//Output: [0]
//Example 3:
//Input: n = 2, edges = [[1,0]]
//Output: [1,1]
// 
//Constraints:
//	1 <= n <= 3 * 104
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	The given input represents a valid tree.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumOfDistancesInTree(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * n); *returnSize = n; int i = 0; for (i = 0; i < n; i++) { result[i] = 0; }

    int* count = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) { count[i] = 0; }
    for (i = 0; i < edgesSize; i++) {
        count[edges[i][0]]++;
        count[edges[i][1]]++;
    }
    for (i = 0; i < n; i++) {
        if (count[i] == 1) { result[i] = 0; }
    }

    int* visited = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) { visited[i] = 0; }

    int* queue = (int*)malloc(sizeof(int) * n);

    int front = 0, rear = 0;

    for (i = 0; i < n; i++) {
        if (count[i] == 1) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (front < rear) {
        int node = queue[front++];
        for (i = 0; i < edgesSize; i++) {
            if (edges[i][0] == node && !visited[edges[i][1]]) {
                result[edges[i][1]] = result[node] + 1;
                visited[edges[i][1]] = 1;
                queue[rear++] = edges[i][1];
            } else if (edges[i][1] == node && !visited[edges[i][0]]) {
                result[edges[i][0]] = result[node] + 1;
                visited[edges[i][0]] = 1;
                queue[rear++] = edges[i][0];
            }
        }
    }
    return result;  
    
}
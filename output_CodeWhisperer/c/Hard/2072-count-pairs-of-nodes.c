/**https://leetcode.com/problems/count-pairs-of-nodes/ */
//You are given an undirected graph defined by an integer n, the number of nodes, and a 2D integer array edges, the edges in the graph, where edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi. You are also given an integer array queries.
//Let incident(a, b) be defined as the number of edges that are connected to either node a or b.
//The answer to the jth query is the number of pairs of nodes (a, b) that satisfy both of the following conditions:
//	a < b
//	incident(a, b) > queries[j]
//Return an array answers such that answers.length == queries.length and answers[j] is the answer of the jth query.
//Note that there can be multiple edges between the same two nodes.
// 
//Example 1:
//Input: n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
//Output: [6,5]
//Explanation: The calculations for incident(a, b) are shown in the table above.
//The answers for each of the queries are as follows:
//- answers[0] = 6. All the pairs have an incident(a, b) value greater than 2.
//- answers[1] = 5. All the pairs except (3, 4) have an incident(a, b) value greater than 3.
//Example 2:
//Input: n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries = [1,2,3,4,5]
//Output: [10,10,9,8,6]
// 
//Constraints:
//	2 <= n <= 2 * 104
//	1 <= edges.length <= 105
//	1 <= ui, vi <= n
//	ui != vi
//	1 <= queries.length <= 20
//	0 <= queries[j] < edges.length
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countPairs(int n, int** edges, int edgesSize, int* edgesColSize, int* queries, int queriesSize, int* returnSize) {
    int* incident = (int*)calloc(n * n, sizeof(int));
    int* degree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0] - 1, v = edges[i][1] - 1;
        incident[u * n + v] = 1;
        incident[v * n + u] = 1;
        degree[u]++;
        degree[v]++;
    }
    int* answer = (int*)malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int count = 0;
        for (int u = 0; u < n - 1; u++) {
            for (int v = u + 1; v < n; v++) {
                int incident_uv = degree[u] + degree[v] - incident[u * n + v];
                if (incident_uv > queries[i]) {
                    count++;
                }
            }
        }
        answer[i] = count;
    }
    *returnSize = queriesSize;
    free(incident);
    free(degree);
    return answer;
}
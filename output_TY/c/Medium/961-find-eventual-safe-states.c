/**https://leetcode.com/problems/find-eventual-safe-states/ */
//There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
//A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
//Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
// 
//Example 1:
//Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
//Output: [2,4,5,6]
//Explanation: The given graph is shown above.
//Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
//Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
//Example 2:
//Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
//Output: [4]
//Explanation:
//Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
// 
//Constraints:
//	n == graph.length
//	1 <= n <= 104
//	0 <= graph[i].length <= n
//	0 <= graph[i][j] <= n - 1
//	graph[i] is sorted in a strictly increasing order.
//	The graph may contain self-loops.
//	The number of edges in the graph will be in the range [1, 4 * 104].
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int) * graphSize);
    memset(ans, 0, sizeof(int) * graphSize);
    int* in = (int*)malloc(sizeof(int) * graphSize);
    memset(in, 0, sizeof(int) * graphSize);
    int* out = (int*)malloc(sizeof(int) * graphSize);
    memset(out, 0,sizeof(int) * graphSize);
    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphColSize[i]; j++) {
            out[i]++;
            in[graph[i][j]]++;
        }
    }
    int* q = (int*)malloc(sizeof(int) * graphSize); 
    int qSize = 0;
    for (int i = 0; i < graphSize; i++) {
        if (in[i] == 0) {
            q[qSize++] = i;
            ans[i] = 1;
        }
    }
    while (qSize) {
        int cur = q[--qSize];
        for (int i = 0; i < graphColSize[cur]; i++) {
            int next = graph[cur][i];
            in[next]--;
            if (in[next] == 0) {
                q[qSize++] = next;
                ans[next] = 1;
            }
        }
    }
    for (int i = 0; i < graphSize; i++) {
        if (ans[i] == 0) {
            ans[i] = 2;
        }
    }
    return ans;
}
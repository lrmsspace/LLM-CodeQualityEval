/**https://leetcode.com/problems/largest-color-value-in-a-directed-graph/ */
//There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
//You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
//A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
//Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
// 
//Example 1:
//Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
//Output: 3
//Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
//Example 2:
//Input: colors = "a", edges = [[0,0]]
//Output: -1
//Explanation: There is a cycle from 0 to 0.
// 
//Constraints:
//	n == colors.length
//	m == edges.length
//	1 <= n <= 105
//	0 <= m <= 105
//	colors consists of lowercase English letters.
//	0 <= aj, bj < n
int largestPathValue(char * colors, int** edges, int edgesSize, int* edgesColSize){
    int n = strlen(colors);
    int* inDegree = (int*)malloc(sizeof(int) * n);
    memset(inDegree, 0, sizeof(int) * n);
    int** graph = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(sizeof(int) * n);
        memset(graph[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < edgesSize; i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
        inDegree[edges[i][1]]++;
    }
    int* queue = (int*)malloc(sizeof(int) * n);
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    int* colorCount = (int*)malloc(sizeof(int) * n);
    memset(colorCount, 0, sizeof(int) * n);
    int maxCount = 0;
    while (front < rear) {
        int node = queue[front++];
        colorCount[node]++;
        maxCount = fmax(maxCount, colorCount[node]);
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1) {
                colorCount[i] = fmax(colorCount[i], colorCount[node]);
                if (--inDegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (inDegree[i] > 0) {
            return -1;
        }
    }
    return maxCount;    
}
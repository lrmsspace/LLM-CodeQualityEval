/**https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/ */
//There is an undirected graph consisting of n nodes numbered from 1 to n. You are given the integer n and a 2D array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi. The graph can be disconnected.
//You can add at most two additional edges (possibly none) to this graph so that there are no repeated edges and no self-loops.
//Return true if it is possible to make the degree of each node in the graph even, otherwise return false.
//The degree of a node is the number of edges connected to it.
// 
//Example 1:
//Input: n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
//Output: true
//Explanation: The above diagram shows a valid way of adding an edge.
//Every node in the resulting graph is connected to an even number of edges.
//Example 2:
//Input: n = 4, edges = [[1,2],[3,4]]
//Output: true
//Explanation: The above diagram shows a valid way of adding two edges.
//Example 3:
//Input: n = 4, edges = [[1,2],[1,3],[1,4]]
//Output: false
//Explanation: It is not possible to obtain a valid graph with adding at most 2 edges.
// 
//Constraints:
//	3 <= n <= 105
//	2 <= edges.length <= 105
//	edges[i].length == 2
//	1 <= ai, bi <= n
//	ai != bi
//	There are no repeated edges.
bool isPossible(int n, int** edges, int edgesSize, int* edgesColSize) {
    int* degree = (int*)calloc(n + 1, sizeof(int));
    int** adj = (int**)calloc(n + 1, sizeof(int*));
    for (int i = 0; i <= n; i++) {
        adj[i] = (int*)calloc(n + 1, sizeof(int));
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        degree[u]++;
        degree[v]++;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    int oddCount = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 == 1) {
            oddCount++;
        }
    }
    if (oddCount > 4) {
        return false;
    }
    if (oddCount == 0) {
        return true;
    }
    if (oddCount == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (degree[i] % 2 == 1 && degree[j] % 2 == 1) {
                    if (!adj[i][j]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    if (oddCount == 4) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    for (int l = k + 1; l <= n; l++) {
                        if (degree[i] % 2 == 1 && degree[j] % 2 == 1 && degree[k] % 2 == 1 && degree[l] % 2 == 1) {
                            if (!adj[i][j] && !adj[i][k] && !adj[i][l] && !adj[j][k] && !adj[j][l] && !adj[k][l]) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
    return false;
}
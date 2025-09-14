/**https://leetcode.com/problems/reachable-nodes-with-restrictions/ */
//There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
//You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.
//Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.
//Note that node 0 will not be a restricted node.
// 
//Example 1:
//Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
//Output: 4
//Explanation: The diagram above shows the tree.
//We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.
//Example 2:
//Input: n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
//Output: 3
//Explanation: The diagram above shows the tree.
//We have that [0,5,6] are the only nodes that can be reached from node 0 without visiting a restricted node.
// 
//Constraints:
//	2 <= n <= 105
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	edges represents a valid tree.
//	1 <= restricted.length < n
//	1 <= restricted[i] < n
//	All the values of restricted are unique.
int reachableNodes(int n, int** edges, int edgesSize, int* edgesColSize, int* restricted, int restrictedSize){  
    int i, j, k, l, m, x, y, z, cnt, ans;
    int *visited, *cnts;
    int **graph;
    
    graph = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j< n; j++) {
            graph[i][j] = 0;
        }
    }
    for (i = 0; i < edgesSize; i++) {
        x = edges[i][0];
        y = edges[i][1];
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    visited = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    cnts = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        cnts[i] = 0;
    }
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            cnt = 0;
            dfs(graph, i, visited, &cnt);
            cnts[i] = cnt;
        }
    }
    return cnts[0];
}
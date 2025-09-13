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

void dfs(int **edges, int edgesSize, int *edgesColSize, int *restricted, int restrictedSize, int node, int *visited, int *count) {
    if (visited[node]) return;
    visited[node] = 1;
    (*count)++;
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][0] == node && !visited[edges[i][1]] && !binary_search(restricted, restricted+restrictedSize, edges[i][1])) {
            dfs(edges, edgesSize, edgesColSize, restricted, restrictedSize, edges[i][1], visited, count);
        } else if (edges[i][1] == node && !visited[edges[i][0]] && !binary_search(restricted, restricted+restrictedSize, edges[i][0])) {
            dfs(edges, edgesSize, edgesColSize, restricted, restrictedSize, edges[i][0], visited, count);
        }
    }
}

bool binary_search(int *arr, int *end, int val) {
    while (arr != end) {
        if (*arr == val) return true;
        if (*arr < val) arr++;  
        else end--;
    }
    return false;
}
int reachableNodes(int n, int** edges, int edgesSize, int* edgesColSize, int* restricted, int restrictedSize) {
    int visited[n];
    memset(visited, 0, sizeof(visited));
    int count = 0;
    dfs(edges, edgesSize, edgesColSize, restricted, restrictedSize, 0, visited, &count);
    return count;
}
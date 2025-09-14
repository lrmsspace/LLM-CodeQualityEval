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
int reachableNodes(int n, int** edges, int edgesSize, int* edgesColSize, int* restricted, int restrictedSize) {
    int* visited = (int*)calloc(n, sizeof(int));
    int** graph = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)calloc(n, sizeof(int));
    }
    for (int i = 0; i < edgesSize; i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }
    int* queue = (int*)calloc(n, sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = 0;
    visited[0] = 1;
    int count = 0;
    while (front < rear) {
        int node = queue[front++];
        count++;
        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                int isRestricted = 0;
                for (int j = 0; j < restrictedSize; j++) {
                    if (i == restricted[j]) {
                        isRestricted = 1;
                        break;
                    }
                }
                if (!isRestricted) {
                    visited[i] = 1;
                    queue[rear++] = i;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(queue);
    free(visited);
    return count;
}
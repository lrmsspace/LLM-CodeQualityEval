/**https://leetcode.com/problems/critical-connections-in-a-network/ */
//There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
//A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
//Return all critical connections in the network in any order.
// 
//Example 1:
//Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
//Output: [[1,3]]
//Explanation: [[3,1]] is also accepted.
//Example 2:
//Input: n = 2, connections = [[0,1]]
//Output: [[0,1]]
// 
//Constraints:
//	2 <= n <= 105
//	n - 1 <= connections.length <= 105
//	0 <= ai, bi <= n - 1
//	ai != bi
//	There are no repeated connections.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes){    
    int** res = NULL;
    *returnSize = 0;    
    *returnColumnSizes = NULL;
    if(n <= 1) return res;
    int* low = malloc(sizeof(int) * n);
    int* dfn = malloc(sizeof(int) * n);
    int* visited = malloc(sizeof(int) * n);
    memset(low, 0, sizeof(int) * n);
    memset(dfn, 0, sizeof(int) * n);
    memset(visited, 0, sizeof(int) * n);
        
    int* head = malloc(sizeof(int) * n);
    memset(head, -1, sizeof(int) * n);
    for(int i = 0; i < connectionsSize; i++){
        int u = connections[i][0];
        int v = connections[i][1];
        addEdge(head, u, v);
    }
    dfs(head, 0, 0, low, dfn, visited, &res, &(*returnSize));
    free(low);
    free(dfn);
    free(visited);
    free(head);
    return res;
}
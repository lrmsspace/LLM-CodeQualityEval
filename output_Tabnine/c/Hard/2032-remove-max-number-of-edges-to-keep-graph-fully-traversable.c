/**https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/ */
//Alice and Bob have an undirected graph of n nodes and three types of edges:
//	Type 1: Can be traversed by Alice only.
//	Type 2: Can be traversed by Bob only.
//	Type 3: Can be traversed by both Alice and Bob.
//Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.
//Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.
// 
//Example 1:
//Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
//Output: 2
//Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
//Example 2:
//Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
//Output: 0
//Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
//Example 3:
//Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
//Output: -1
//Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
// 
// 
//Constraints:
//	1 <= n <= 105
//	1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
//	edges[i].length == 3
//	1 <= typei <= 3
//	1 <= ui < vi <= n
//	All tuples (typei, ui, vi) are distinct.
int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize) {
    
    int* indegree = (int*)calloc(n+1, sizeof(int));
    int* outdegree = (int*)calloc(n+1, sizeof(int));
    int count = 0;
    
    for (int i = 0; i < edgesSize; i++) {
        int type = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];
        
        if (type == 1) {
            indegree[v]++;
            outdegree[u]++;
        } else if (type == 2) {
            indegree[u]++;
            outdegree[v]++;
        } else {
            indegree[u]++;
            outdegree[v]++;
            count++;
        }
    }
    
    int maxEdges = 0;
    int maxAlice = 0;
    int maxBob = 0;
    
    for (int i = 1; i <= n; i++) {
        maxAlice = max(maxAlice, indegree[i]);
        maxBob = max(maxBob, outdegree[i]);
    }
    
    if (maxAlice > maxBob) {
        return -1;
    }
    
    while (count < n - 1 && maxAlice > 0 && maxBob > 0) {
        int u = 0;
        int v = 0;
        
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == maxAlice - 1 && outdegree[i] > 0) {
                u = i;
            }
            if (outdegree[i] == maxBob - 1 && indegree[i] > 0) {
                v = i;
            }
        }
        
        if (u == 0 || v == 0) {
            return -1;
        }
        
        indegree[v]--;
        outdegree[u]--;
        count++;
        maxAlice--;
        maxBob--;
        maxEdges++;
    }
    
    return maxEdges;
}
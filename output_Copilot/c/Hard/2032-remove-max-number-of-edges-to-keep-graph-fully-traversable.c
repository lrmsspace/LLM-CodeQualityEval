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
    int* parent = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int* idx = (int*)malloc(sizeof(int) * edgesSize);
    for (int i = 0; i < edgesSize; i++) {
        idx[i] = i;
    }
    qsort(idx, edgesSize, sizeof(int), cmp);
    int* weight = (int*)malloc(sizeof(int) * edgesSize);
    for (int i = 0; i < edgesSize; i++) {
        weight[i] = edges[idx[i]][0];
    }
    int* find = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        find[i] = i;
    }
    int* rank = (int*)malloc(sizeof(int) * n);
    memset(rank, 0, sizeof(int) * n);
    int* size = (int*)malloc(sizeof(int) * n);
    memset(size, 1, sizeof(int) * n);
    int* mst = (int*)malloc(sizeof(int) * n);
    int* mstIdx = (int*)malloc(sizeof(int) * n);
    int* mstType = (int*)malloc(sizeof(int) * n);
    int* mstSize = (int*)malloc(sizeof(int) * n);
    int* mstRank = (int*)malloc(sizeof(int) * n);
    int* mstParent = (int*)malloc(sizeof(int) * n);
    int* mstFind = (int*)malloc(sizeof(int) * n);
    int* mstWeight = (int*)malloc(sizeof(int) * n);
    memset(mstWeight, 0, sizeof(int) * n);

    int removedEdges = 0;

    // Helper function to find the root of a node
    int findRoot(int* parent, int node) {
        if (parent[node] != node) {
            parent[node] = findRoot(parent, parent[node]);
        }
        return parent[node];
    }

    // Helper function to union two nodes
    int unionNodes(int* parent, int* rank, int u, int v) {
        int rootU = findRoot(parent, u);
        int rootV = findRoot(parent, v);

        if (rootU == rootV) {
            return 0; // Already connected
        }

        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }

        return 1; // Successfully connected
    }

    // Process type 3 edges first (usable by both Alice and Bob)
    for (int i = 0; i < edgesSize; i++) {
        if (edges[idx[i]][0] == 3) {
            if (!unionNodes(parent, rank, edges[idx[i]][1] - 1, edges[idx[i]][2] - 1)) {
                removedEdges++;
            }
        }
    }

    // Copy parent and rank arrays for Alice and Bob
    int* parentAlice = (int*)malloc(sizeof(int) * n);
    int* parentBob = (int*)malloc(sizeof(int) * n);
    memcpy(parentAlice, parent, sizeof(int) * n);
    memcpy(parentBob, parent, sizeof(int) * n);

    int* rankAlice = (int*)malloc(sizeof(int) * n);
    int* rankBob = (int*)malloc(sizeof(int) * n);
    memcpy(rankAlice, rank, sizeof(int) * n);
    memcpy(rankBob, rank, sizeof(int) * n);

    // Process type 1 edges (usable by Alice only)
    for (int i = 0; i < edgesSize; i++) {
        if (edges[idx[i]][0] == 1) {
            if (!unionNodes(parentAlice, rankAlice, edges[idx[i]][1] - 1, edges[idx[i]][2] - 1)) {
                removedEdges++;
            }
        }
    }

    // Process type 2 edges (usable by Bob only)
    for (int i = 0; i < edgesSize; i++) {
        if (edges[idx[i]][0] == 2) {
            if (!unionNodes(parentBob, rankBob, edges[idx[i]][1] - 1, edges[idx[i]][2] - 1)) {
                removedEdges++;
            }
        }
    }

    // Check if both Alice and Bob can traverse the entire graph
    int rootAlice = findRoot(parentAlice, 0);
    int rootBob = findRoot(parentBob, 0);
    for (int i = 1; i < n; i++) {
        if (findRoot(parentAlice, i) != rootAlice || findRoot(parentBob, i) != rootBob) {
            free(parent);
            free(idx);
            free(weight);
            free(find);
            free(rank);
            free(size);
            free(mst);
            free(mstIdx);
            free(mstType);
            free(mstSize);
            free(mstRank);
            free(mstParent);
            free(mstFind);
            free(mstWeight);
            free(parentAlice);
            free(parentBob);
            free(rankAlice);
            free(rankBob);
            return -1;
        }
    }

    free(parent);
    free(idx);
    free(weight);
    free(find);
    free(rank);
    free(size);
    free(mst);
    free(mstIdx);
    free(mstType);
    free(mstSize);
    free(mstRank);
    free(mstParent);
    free(mstFind);
    free(mstWeight);
    free(parentAlice);
    free(parentBob);
    free(rankAlice);
    free(rankBob);

    return removedEdges;    
}
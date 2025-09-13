/*
 There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
 Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
 The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
 Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.
 Since the answer may be large, return it modulo 109 + 7.
 Note: Ignore all edges not in the path from node 1 to x.
 Example 1:
 Input: edges = [[1,2]]
 Output: 1
 Explanation:
 The path from Node 1 to Node 2 consists of one edge (1 → 2).
 Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
 Example 2:
 Input: edges = [[1,2],[1,3],[3,4],[3,5]]
 Output: 2
 Explanation:
 The maximum depth is 2, with nodes 4 and 5 at the same depth. Either node can be selected for processing.
 For example, the path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4).
 Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
 Constraints:
 2 <= n <= 105
 edges.length == n - 1
 edges[i] == [ui, vi]
 1 <= ui, vi <= n
 edges represents a valid tree.
*/

int assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize) {
    
    int n = edgesSize + 1;
    int *visited = (int*)malloc(n * sizeof(int));
    memset(visited, 0, n * sizeof(int));
    int *depth = (int*)malloc(n * sizeof(int));
    memset(depth, 0, n * sizeof(int));
    int *parent = (int*)malloc(n * sizeof(int));
    memset(parent, 0, n * sizeof(int));
    int *odd = (int*)malloc(n * sizeof(int));
    memset(odd, 0, n * sizeof(int));
    int *even = (int*)malloc(n * sizeof(int));
    memset(even, 0, n * sizeof(int));

    for (int i = 0; i < n; i++) {
        odd[i] = 1;
        even[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        int cur = i;
        int d = 0;
        while (cur != -1) {
            visited[cur] = 1;
            depth[cur] = d;
            parent[cur] = i;
            cur = edges[cur][0] == i ? edges[cur][1] : edges[cur][0];
            d++;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (depth[i] == 0) continue;
        int cur = i;
        while (cur != -1) {
            int p = parent[cur];
            if (depth[p] == depth[cur] - 1) {
                odd[p] *= odd[cur];
                even[p] *= even[cur];
            } else {
                odd[p] *= even[cur];
                even[p] *= odd[cur];
            }
            cur = p;
        }
    }
    return odd[0];

}
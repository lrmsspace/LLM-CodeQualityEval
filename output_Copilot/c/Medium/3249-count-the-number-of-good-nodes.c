/*
 There is an undirected tree with n nodes labeled from 0 to n - 1, and rooted at node 0. You are given a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
 A node is good if all the subtrees rooted at its children have the same size.
 Return the number of good nodes in the given tree.
 A subtree of treeName is a tree consisting of a node in treeName and all of its descendants.
 Example 1:
 Input: edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
 Output: 7
 Explanation:
 All of the nodes of the given tree are good.
 Example 2:
 Input: edges = [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]
 Output: 6
 Explanation:
 There are 6 good nodes in the given tree. They are colored in the image above.
 Example 3:
 Input: edges = [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]
 Output: 12
 Explanation:
 All nodes except node 9 are good.
 Constraints:
 2 <= n <= 105
 edges.length == n - 1
 edges[i].length == 2
 0 <= ai, bi < n
 The input is generated such that edges represents a valid tree.
*/

int countGoodNodes(int** edges, int edgesSize, int* edgesColSize) {
    int n = edgesSize + 1;
    int* subtreeSize = (int*)calloc(n, sizeof(int));
    int* goodNodeCount = (int*)calloc(n, sizeof(int));
    int goodNodeTotal = 0;

    // Build the adjacency list
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        memset(graph[i], -1, n * sizeof(int));
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // DFS to calculate subtree sizes
    void dfs(int node, int parent) {
        subtreeSize[node] = 1;
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && i != parent) {
                dfs(i, node);
                subtreeSize[node] += subtreeSize[i];
            }
        }
    }
    dfs(0, -1);

    // Count good nodes
    for (int i = 0; i < n; i++) {
        int isGood = 1;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                if (subtreeSize[j] != subtreeSize[i] / 2) {
                    isGood = 0;
                    break;
                }
            }
        }
        if (isGood) {
            goodNodeCount[i] = 1;
            goodNodeTotal++;
        }
    }

    // Clean up
    free(subtreeSize);
    free(goodNodeCount);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return goodNodeTotal;
}
/*
 There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
 You must connect one node from the first tree with another node from the second tree with an edge.
 Return the minimum possible diameter of the resulting tree.
 The diameter of a tree is the length of the longest path between any two nodes in the tree.
 Example 1:
 Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]
 Output: 3
 Explanation:
 We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.
 Example 2:
 Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]
 Output: 5
 Explanation:
 We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.
 Constraints:
 1 <= n, m <= 105
 edges1.length == n - 1
 edges2.length == m - 1
 edges1[i].length == edges2[i].length == 2
 edges1[i] = [ai, bi]
 0 <= ai, bi < n
 edges2[i] = [ui, vi]
 0 <= ui, vi < m
 The input is generated such that edges1 and edges2 represent valid trees.
*/    // Helper function to find the longest path from a node using DFS
void dfs(int node, int parent, int* maxDist, int* farthestNode, int dist, int** adj, int* adjSize, int n) {
    if (dist > *maxDist) {
        *maxDist = dist;
        *farthestNode = node;
    }
    
    for (int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if (next != parent) {
            dfs(next, node, maxDist, farthestNode, dist + 1, adj, adjSize, n);
        }
    }
}

// Helper function to find diameter of a tree
int getDiameter(int node, int** adj, int* adjSize, int n) {
    int maxDist = 0;
    int farthestNode = 0;
    
    // Find farthest node from given node
    dfs(node, -1, &maxDist, &farthestNode, 0, adj, adjSize, n);
    
    // Find farthest node from the previously found farthest node
    maxDist = 0;
    int temp = 0;
    dfs(farthestNode, -1, &maxDist, &temp, 0, adj, adjSize, n);
    
    return maxDist;
}

// Helper function to find height of a tree from a node
int getHeight(int node, int parent, int** adj, int* adjSize) {
    int maxHeight = 0;
    
    for (int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if (next != parent) {
            maxHeight = fmax(maxHeight, 1 + getHeight(next, node, adj, adjSize));
        }
    }
    
    return maxHeight;
}

int minimumDiameterAfterMerge(int** edges1, int edges1Size, int* edges1ColSize, int** edges2, int edges2Size, int* edges2ColSize) {
    int n = edges1Size + 1;
    int m = edges2Size + 1;
    
    // Build adjacency lists
    int** adj1 = (int**)malloc(n * sizeof(int*));
    int** adj2 = (int**)malloc(m * sizeof(int*));
    int* adjSize1 = (int*)calloc(n, sizeof(int));
    int* adjSize2 = (int*)calloc(m, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        adj1[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        adj2[i] = (int*)malloc(m * sizeof(int));
    }
    
    // Fill adjacency lists
    for (int i = 0; i < edges1Size; i++) {
        int u = edges1[i][0], v = edges1[i][1];
        adj1[u][adjSize1[u]++] = v;
        adj1[v][adjSize1[v]++] = u;
    }
    
    for (int i = 0; i < edges2Size; i++) {
        int u = edges2[i][0], v = edges2[i][1];
        adj2[u][adjSize2[u]++] = v;
        adj2[v][adjSize2[v]++] = u;
    }
    
    int minDiameter = INT_MAX;
    
    // Try connecting each node from tree1 to each node from tree2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Get heights from both nodes
            int h1 = getHeight(i, -1, adj1, adjSize1);
            int h2 = getHeight(j, -1, adj2, adjSize2);
            
            // Get diameters of both trees
            int d1 = getDiameter(0, adj1, adjSize1, n);
            int d2 = getDiameter(0, adj2, adjSize2, m);
            
            // New diameter will be maximum of:
            // 1. Diameter of tree1
            // 2. Diameter of tree2
            // 3. Height from node i in tree1 + Height from node j in tree2 + 1
            int newDiameter = fmax(fmax(d1, d2), h1 + h2 + 1);
            minDiameter = fmin(minDiameter, newDiameter);
        }
    }
    
    // Free memory
    for (int i = 0; i < n; i++) {
        free(adj1[i]);
    }
    for (int i = 0; i < m; i++) {
        free(adj2[i]);
    }
    free(adj1);
    free(adj2);
    free(adjSize1);
    free(adjSize2);
    
    return minDiameter;
}    
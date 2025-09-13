/*
 You are given an undirected tree rooted at node 0, with n nodes numbered from 0 to n - 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates an edge between nodes ui and vi.
 You are also given an integer array nums of length n, where nums[i] represents the value at node i, and an integer k.
 You may perform inversion operations on a subset of nodes subject to the following rules:
 Subtree Inversion Operation:
 When you invert a node, every value in the subtree rooted at that node is multiplied by -1.
 Distance Constraint on Inversions:
 You may only invert a node if it is "sufficiently far" from any other inverted node.
 Specifically, if you invert two nodes a and b such that one is an ancestor of the other (i.e., if LCA(a, b) = a or LCA(a, b) = b), then the distance (the number of edges on the unique path between them) must be at least k.
 Return the maximum possible sum of the tree's node values after applying inversion operations.
 Example 1:
 Input: edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], nums = [4,-8,-6,3,7,-2,5], k = 2
 Output: 27
 Explanation:
 Apply inversion operations at nodes 0, 3, 4 and 6.
 The final nums array is [-4, 8, 6, 3, 7, 2, 5], and the total sum is 27.
 Example 2:
 Input: edges = [[0,1],[1,2],[2,3],[3,4]], nums = [-1,3,-2,4,-5], k = 2
 Output: 9
 Explanation:
 Apply the inversion operation at node 4.
 The final nums array becomes [-1, 3, -2, 4, 5], and the total sum is 9.
 Example 3:
 Input: edges = [[0,1],[0,2]], nums = [0,-1,-2], k = 3
 Output: 3
 Explanation:
 Apply inversion operations at nodes 1 and 2.
 Constraints:
 2 <= n <= 5 * 104
 edges.length == n - 1
 edges[i] = [ui, vi]
 0 <= ui, vi < n
 nums.length == n
 -5 * 104 <= nums[i] <= 5 * 104
 1 <= k <= 50
 The input is generated such that edges represents a valid tree.
*/

long long subtreeInversionSum(int** edges, int edgesSize, int* edgesColSize, int* nums, int numsSize, int k) {
    // Build adjacency list representation of tree
    int* adj[numsSize];
    int adjSize[numsSize];
    for(int i = 0; i < numsSize; i++) {
        adj[i] = (int*)malloc(numsSize * sizeof(int));
        adjSize[i] = 0;
    }
    
    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // dp[i][0] - max sum without inverting node i
    // dp[i][1] - max sum when inverting node i
    long long dp[numsSize][2];
    int parent[numsSize];
    int depth[numsSize];
    
    // DFS to compute depths and parents
    void dfs1(int node, int p, int d) {
        parent[node] = p;
        depth[node] = d;
        for(int i = 0; i < adjSize[node]; i++) {
            int next = adj[node][i];
            if(next != p) {
                dfs1(next, node, d + 1);
            }
        }
    }
    
    // DFS to compute dp values
    void dfs2(int node, int p) {
        dp[node][0] = nums[node];
        dp[node][1] = -nums[node];
        
        for(int i = 0; i < adjSize[node]; i++) {
            int next = adj[node][i];
            if(next != p) {
                dfs2(next, node);
                
                // Not inverting current node
                dp[node][0] += dp[next][0];
                
                // Inverting current node
                dp[node][1] -= dp[next][0];
            }
        }
        
        // Check if we can invert this node based on k-distance constraint
        int curr = node;
        while(curr != 0 && depth[node] - depth[curr] < k) {
            curr = parent[curr];
            if(dp[curr][1] > dp[curr][0]) {
                dp[node][1] = dp[node][0];
                break;
            }
        }
    }
    
    dfs1(0, -1, 0);
    dfs2(0, -1);
    
    // Free allocated memory
    for(int i = 0; i < numsSize; i++) {
        free(adj[i]);
    }
    
    return dp[0][0] > dp[0][1] ? dp[0][0] : dp[0][1];
}            

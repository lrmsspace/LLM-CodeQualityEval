/*
 You are given an undirected tree with n nodes labeled from 0 to n - 1, and rooted at node 0. You are given a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
 You are also given a 0-indexed integer array cost of length n, where cost[i] is the cost assigned to the ith node.
 You need to place some coins on every node of the tree. The number of coins to be placed at node i can be calculated as:
 If size of the subtree of node i is less than 3, place 1 coin.
 Otherwise, place an amount of coins equal to the maximum product of cost values assigned to 3 distinct nodes in the subtree of node i. If this product is negative, place 0 coins.
 Return an array coin of size n such that coin[i] is the number of coins placed at node i.
 Example 1:
 Input: edges = [[0,1],[0,2],[0,3],[0,4],[0,5]], cost = [1,2,3,4,5,6]
 Output: [120,1,1,1,1,1]
 Explanation: For node 0 place 6 * 5 * 4 = 120 coins. All other nodes are leaves with subtree of size 1, place 1 coin on each of them.
 Example 2:
 Input: edges = [[0,1],[0,2],[1,3],[1,4],[1,5],[2,6],[2,7],[2,8]], cost = [1,4,2,3,5,7,8,-4,2]
 Output: [280,140,32,1,1,1,1,1,1]
 Explanation: The coins placed on each node are:
 - Place 8 * 7 * 5 = 280 coins on node 0.
 - Place 7 * 5 * 4 = 140 coins on node 1.
 - Place 8 * 2 * 2 = 32 coins on node 2.
 - All other nodes are leaves with subtree of size 1, place 1 coin on each of them.
 Example 3:
 Input: edges = [[0,1],[0,2]], cost = [1,2,-2]
 Output: [0,1,1]
 Explanation: Node 1 and 2 are leaves with subtree of size 1, place 1 coin on each of them. For node 0 the only possible product of cost is 2 * 1 * -2 = -4. Hence place 0 coins on node 0.
 Constraints:
 2 <= n <= 2 * 104
 edges.length == n - 1
 edges[i].length == 2
 0 <= ai, bi < n
 cost.length == n
 1 <= |cost[i]| <= 104
 The input is generated such that edges represents a valid tree.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* placedCoins(int** edges, int edgesSize, int* edgesColSize, int* cost, int costSize, int* returnSize) {
    // Create adjacency list representation
    int* adj[costSize];
    int adjSize[costSize];
    for(int i = 0; i < costSize; i++) {
        adj[i] = (int*)malloc(costSize * sizeof(int));
        adjSize[i] = 0;
    }
    
    // Build adjacency list
    for(int i = 0; i < edgesSize; i++) {
        adj[edges[i][0]][adjSize[edges[i][0]]++] = edges[i][1];
        adj[edges[i][1]][adjSize[edges[i][1]]++] = edges[i][0];
    }
    
    // Result array
    long long* result = (long long*)malloc(costSize * sizeof(long long));
    *returnSize = costSize;
    
    // DFS helper function
    void dfs(int node, int parent, int* maxVals, int* maxSize) {
        int vals[costSize];
        int size = 0;
        
        // Add current node cost
        vals[size++] = cost[node];
        
        // Recursively process children
        for(int i = 0; i < adjSize[node]; i++) {
            int child = adj[node][i];
            if(child != parent) {
                int childVals[costSize];
                int childSize = 0;
                dfs(child, node, childVals, &childSize);
                
                // Merge child values
                for(int j = 0; j < childSize; j++) {
                    vals[size++] = childVals[j];
                }
            }
        }
        
        // Sort values in descending order
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                if(vals[j] > vals[i]) {
                    int temp = vals[i];
                    vals[i] = vals[j];
                    vals[j] = temp;
                }
            }
        }
        
        // Calculate coins for current node
        if(size < 3) {
            result[node] = 1;
        } else {
            long long prod = (long long)vals[0] * vals[1] * vals[2];
            result[node] = prod > 0 ? prod : 0;
        }
        
        // Return values for parent
        for(int i = 0; i < size; i++) {
            maxVals[i] = vals[i];
        }
        *maxSize = size;
    }
    
    // Start DFS from root
    int rootVals[costSize];
    int rootSize = 0;
    dfs(0, -1, rootVals, &rootSize);
    
    // Free adjacency lists
    for(int i = 0; i < costSize; i++) {
        free(adj[i]);
    }
    
    return result;
}            

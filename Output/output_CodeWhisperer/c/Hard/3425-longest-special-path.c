/*
 You are given an undirected tree rooted at node 0 with n nodes numbered from 0 to n - 1, represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, lengthi] indicates an edge between nodes ui and vi with length lengthi. You are also given an integer array nums, where nums[i] represents the value at node i.
 A special path is defined as a downward path from an ancestor node to a descendant node such that all the values of the nodes in that path are unique.
 Note that a path may start and end at the same node.
 Return an array result of size 2, where result[0] is the length of the longest special path, and result[1] is the minimum number of nodes in all possible longest special paths.
 Example 1:
 Input: edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], nums = [2,1,2,1,3,1]
 Output: [6,2]
 Explanation:
 In the image below, nodes are colored by their corresponding values in nums
 The longest special paths are 2 -> 5 and 0 -> 1 -> 4, both having a length of 6. The minimum number of nodes across all longest special paths is 2.
 Example 2:
 Input: edges = [[1,0,8]], nums = [2,2]
 Output: [0,1]
 Explanation:
 The longest special paths are 0 and 1, both having a length of 0. The minimum number of nodes across all longest special paths is 1.
 Constraints:
 2 <= n <= 5 * 104
 edges.length == n - 1
 edges[i].length == 3
 0 <= ui, vi < n
 1 <= lengthi <= 103
 nums.length == n
 0 <= nums[i] <= 5 * 104
 The input is generated such that edges represents a valid tree.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* longestSpecialPath(int** edges, int edgesSize, int* edgesColSize, int* nums, int numsSize, int* returnSize) {
    // Create adjacency list representation
    int** adj = (int**)malloc(numsSize * sizeof(int*));
    int* adjSize = (int*)calloc(numsSize, sizeof(int));
    int** weights = (int**)malloc(numsSize * sizeof(int*));
    
    // Count neighbors for each node
    for(int i = 0; i < edgesSize; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }
    
    // Allocate memory for adjacency lists
    for(int i = 0; i < numsSize; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        weights[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }
    
    // Build adjacency lists with weights
    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        adj[u][adjSize[u]] = v;
        weights[u][adjSize[u]++] = w;
        adj[v][adjSize[v]] = u;
        weights[v][adjSize[v]++] = w;
    }
    
    int maxLen = 0;
    int minNodes = numsSize;
    
    // DFS function to find longest special path
    void dfs(int node, int parent, int len, int* path, int pathSize) {
        path[nums[node]]++;
        
        // If current path is valid and longer
        if(path[nums[node]] == 1) {
            if(len > maxLen) {
                maxLen = len;
                minNodes = pathSize;
            } else if(len == maxLen) {
                minNodes = pathSize < minNodes ? pathSize : minNodes;
            }
        }
        
        // Try all neighbors
        for(int i = 0; i < adjSize[node]; i++) {
            int next = adj[node][i];
            if(next != parent && path[nums[next]] == 0) {
                dfs(next, node, len + weights[node][i], path, pathSize + 1);
            }
        }
        
        path[nums[node]]--;
    }
    
    // Try starting DFS from each node
    int* path = (int*)calloc(50001, sizeof(int));
    for(int i = 0; i < numsSize; i++) {
        dfs(i, -1, 0, path, 1);
    }
    
    // Free allocated memory
    for(int i = 0; i < numsSize; i++) {
        free(adj[i]);
        free(weights[i]);
    }
    free(adj);
    free(weights);
    free(adjSize);
    free(path);
    
    // Return result
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = maxLen;
    result[1] = minNodes;
    return result;
}    
/*
 You are given an undirected tree rooted at node 0, with n nodes numbered from 0 to n - 1. This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, lengthi] indicates an edge between nodes ui and vi with length lengthi. You are also given an integer array nums, where nums[i] represents the value at node i.
 A special path is defined as a downward path from an ancestor node to a descendant node in which all node values are distinct, except for at most one value that may appear twice.
 Return an array result of size 2, where result[0] is the length of the longest special path, and result[1] is the minimum number of nodes in all possible longest special paths.
 Example 1:
 Input: edges = [[0,1,1],[1,2,3],[1,3,1],[2,4,6],[4,7,2],[3,5,2],[3,6,5],[6,8,3]], nums = [1,1,0,3,1,2,1,1,0]
 Output: [9,3]
 Explanation:
 In the image below, nodes are colored by their corresponding values in nums.
 The longest special paths are 1 -> 2 -> 4 and 1 -> 3 -> 6 -> 8, both having a length of 9. The minimum number of nodes across all longest special paths is 3.
 Example 2:
 Input: edges = [[1,0,3],[0,2,4],[0,3,5]], nums = [1,1,0,2]
 Output: [5,2]
 Explanation:
 The longest path is 0 -> 3 consisting of 2 nodes with a length of 5.
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
    
    // DFS from each node
    for(int i = 0; i < numsSize; i++) {
        int* visited = (int*)calloc(numsSize, sizeof(int));
        int* count = (int*)calloc(5 * 10000 + 1, sizeof(int));
        count[nums[i]] = 1;
        visited[i] = 1;
        
        // Try each neighbor as start of path
        for(int j = 0; j < adjSize[i]; j++) {
            int len = weights[i][adjSize[j]];
            int nodes = 1;
            int dup = 0;
            
            if(count[nums[adj[i][j]]] == 1) dup = 1;
            count[nums[adj[i][j]]]++;
            visited[adj[i][j]] = 1;
            
            dfs(adj[i][j], adj, weights, adjSize, nums, visited, count, &len, &nodes, &dup, &maxLen, &minNodes);
            
            count[nums[adj[i][j]]]--;
            visited[adj[i][j]] = 0;
        }
        
        free(visited);
        free(count);
    }
    
    // Free allocated memory
    for(int i = 0; i < numsSize; i++) {
        free(adj[i]);
        free(weights[i]);
    }
    free(adj);
    free(weights);
    free(adjSize);
    
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = maxLen;
    result[1] = minNodes;
    return result;
}

void dfs(int node, int** adj, int** weights, int* adjSize, int* nums, int* visited, int* count, 
        int* len, int* nodes, int* dup, int* maxLen, int* minNodes) {
    
    // Update max length and min nodes if current path is valid
    if(*len > *maxLen && *dup <= 1) {
        *maxLen = *len;
        *minNodes = *nodes;
    } else if(*len == *maxLen && *dup <= 1) {
        *minNodes = (*nodes < *minNodes) ? *nodes : *minNodes;
    }
    
    // Try extending path through each unvisited neighbor
    for(int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if(!visited[next]) {
            int newDup = *dup;
            if(count[nums[next]] == 1) newDup++;
            
            if(newDup <= 1) {
                count[nums[next]]++;
                visited[next] = 1;
                *len += weights[node][i];
                (*nodes)++;
                
                dfs(next, adj, weights, adjSize, nums, visited, count, len, nodes, &newDup, maxLen, minNodes);
                
                count[nums[next]]--;
                visited[next] = 0;
                *len -= weights[node][i];
                (*nodes)--;
            }
        }
    }
}    
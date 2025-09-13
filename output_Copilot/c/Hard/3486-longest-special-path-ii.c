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
    // Initialize the result array
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = 0; // Length of the longest special path
    result[1] = 0; // Minimum number of nodes in all possible longest special paths

    // Create an adjacency list for the tree
    int n = numsSize;
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = -1; // Initialize with -1 to indicate no edge
        }
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int length = edges[i][2];
        graph[u][v] = length;
        graph[v][u] = length;
    }

    // DFS function to find the longest special path
    void dfs(int node, int parent, int currentLength, int* visited, int* maxLength, int* minNodes) {
        visited[node] = 1;

        // Check if the current path is valid
        int uniqueCount = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] && nums[i] == nums[node]) {
                uniqueCount++;
            }
        }

        if (uniqueCount <= 2) { // At most one value can appear twice
            if (currentLength > *maxLength) {
                *maxLength = currentLength;
                *minNodes = 1; // Reset minNodes count
            } else if (currentLength == *maxLength) {
                (*minNodes)++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (graph[node][i] != -1 && i != parent && !visited[i]) {
                dfs(i, node, currentLength + graph[node][i], visited, maxLength, minNodes);
            }
        }

        visited[node] = 0; // Backtrack
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int maxLength = 0;
    int minNodes = n; // Start with maximum possible nodes
    dfs(0, -1, 0, visited, &maxLength, &minNodes);
    result[0] = maxLength;
    result[1] = minNodes;
    free(visited);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    *returnSize = 2; // Set the return size
    return result;
    
}
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
            if (visited[i]) {
                uniqueCount++;
            }
        }

        if (currentLength > *maxLength) {
            *maxLength = currentLength;
            *minNodes = uniqueCount;
        } else if (currentLength == *maxLength) {
            *minNodes = (*minNodes < uniqueCount) ? *minNodes : uniqueCount;
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
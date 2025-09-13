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
// Helper function to perform DFS and calculate the longest special path
void dfs(int node, int parent, int** edges, int* edgesColSize, int* nums, int* visited, int* maxLength, int* minNodes, int currentLength, int currentNodes, int* currentValues) {
    visited[node] = 1;
    currentValues[nums[node]]++;

    for(int i = 0; i < edgesColSize[node]; i++) {
        int neighbor = edges[node][i];
        if (neighbor == parent || visited[neighbor]) continue;

        if (currentValues[nums[neighbor]] == 0) {
            dfs(neighbor, node, edges, edgesColSize, nums, visited, maxLength, minNodes, currentLength + 1, currentNodes + 1, currentValues);
        }
    }

    if (currentLength > *maxLength || (currentLength == *maxLength && currentNodes < *minNodes)) {
        *maxLength = currentLength;
        *minNodes = currentNodes;
    }

    currentValues[nums[node]]--;
    visited[node] = 0;
}

int* longestSpecialPath(int** edges, int edgesSize, int* edgesColSize, int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int* visited = (int*)calloc(numsSize, sizeof(int));
    int* currentValues = (int*)calloc(50001, sizeof(int)); // 0 <= nums[i] <= 5 * 10^4

    result[0] = 0; // maxLength
    result[1] = numsSize; // minNodes

    dfs(0, -1, edges, edgesColSize, nums, visited, &result[0], &result[1], 0, 1, currentValues);

    free(visited);
    free(currentValues);

    return result;
}


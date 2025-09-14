/**https://leetcode.com/problems/permutations/ */
//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//Example 2:
//Input: nums = [0,1]
//Output: [[0,1],[1,0]]
//Example 3:
//Input: nums = [1]
//Output: [[1]]
// 
//Constraints:
//	1 <= nums.length <= 6
//	-10 <= nums[i] <= 10
//	All the integers of nums are unique.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 720);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 720);
    *returnSize = 0;
    int* visited = (int*)calloc(numsSize, sizeof(int));
    int* path = (int*)malloc(sizeof(int) * numsSize);
    int* pathIndex = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        pathIndex[i] = i;
    }
    void dfs(int depth) {
        if (depth == numsSize) {
            result[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
            for (int i = 0; i < numsSize; i++) {
                result[*returnSize][i] = nums[path[i]];
            }
            (*returnColumnSizes)[*returnSize] = numsSize;
            (*returnSize)++;
            return;
        }
        for (int i = 0; i < numsSize; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                path[depth] = pathIndex[i];
                dfs(depth + 1);
                visited[i] = 0;
            }
        }
    }
    dfs(0);
    free(visited);
    free(path);
    free(pathIndex);
    return result;
}
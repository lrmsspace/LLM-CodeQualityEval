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
    int** res = (int**)malloc(sizeof(int*) * 10000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);
    int** temp = (int**)malloc(sizeof(int*) * 10000);
    int* tempColumnSizes = (int*)malloc(sizeof(int) * 10000);
    int tempSize = 0;
    int resSize = 0;
    int* columnSizes = *returnColumnSizes;
    int* arr = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        arr[i] = nums[i];
    }
    int* visited = (int*)malloc(sizeof(int) * numsSize);
    memset(visited, 0, sizeof(int) * numsSize);
    int* path = (int*)malloc(sizeof(int) * numsSize);
    int pathSize = 0;
    dfs(arr, numsSize, visited, path, pathSize, res, &resSize, &columnSizes, temp, &tempSize, &tempColumnSizes);
    *returnSize = resSize;
    return res;    
}
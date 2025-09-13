/**https://leetcode.com/problems/permutations-ii/ */
//Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
// 
//Example 1:
//Input: nums = [1,1,2]
//Output:
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
//Example 2:
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//Constraints:
//	1 <= nums.length <= 8
//	-10 <= nums[i] <= 10
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(sizeof(int*) * 10000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    int* path = (int*)malloc(sizeof(int) * numsSize);
    int* used = (int*)malloc(sizeof(int) * numsSize);
    int** cmp = (int**)malloc(sizeof(int*) * 10000);
    int cmpSize = 0;
    for (int i = 0; i < numsSize; i++) {
        used[i] = 0;
    }
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    dfs(nums, numsSize, 0, path, used, res, returnSize, returnColumnSizes, cmp, &cmpSize);
    return res;    
}
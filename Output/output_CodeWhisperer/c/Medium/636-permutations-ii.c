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
    int** result = (int**)malloc(sizeof(int*) * 10000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    int* used = (int*)malloc(sizeof(int) * numsSize);
    int* path = (int*)malloc(sizeof(int) * numsSize);
    int* visited = (int*)malloc(sizeof(int) * numsSize);
    memset(visited, 0, sizeof(int) * numsSize);
    int* sorted_nums = (int*)malloc(sizeof(int) * numsSize);
    memcpy(sorted_nums, nums, sizeof(int) * numsSize);
    qsort(sorted_nums, numsSize, sizeof(int), cmp);
    dfs(nums, numsSize, sorted_nums, numsSize, path, 0, used, visited, result, returnColumnSizes, returnSize);
    return result;

}
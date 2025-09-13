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
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        (*returnColumnSizes)[i] = numsSize - i;
    }
    
    int** result = (int**)malloc(sizeof(int*) * factorial(numsSize));
    int* visited = (int*)calloc(numsSize, sizeof(int));
    backtrack(nums, numsSize, visited, 0, result, returnSize);
    
    free(visited);
    return result;
    
}
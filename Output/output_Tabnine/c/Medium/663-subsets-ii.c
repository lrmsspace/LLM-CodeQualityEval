/**https://leetcode.com/problems/subsets-ii/ */
//Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.
// 
//Example 1:
//Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
//Example 2:
//Input: nums = [0]
//Output: [[],[0]]
// 
//Constraints:
//	1 <= nums.length <= 10
//	-10 <= nums[i] <= 10
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Sort the array to handle duplicates
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Initialize the result array
    int** result = (int**)malloc(sizeof(int*) * power(2, numsSize));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * power(2, numsSize));
    
    // Initialize the helper array
    int* helper = (int*)malloc(sizeof(int) * numsSize);
    
    // Recursively generate subsets
    backtrack(nums, 0, numsSize, helper, result, returnSize, returnColumnSizes);
    
    // Free the helper array
    free(helper);
    
    return result;
    
}
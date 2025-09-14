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


int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    *returnSize = 0;
    int maxSets = 1 << numsSize;
    int **result = malloc(maxSets * sizeof(int *));
    *returnColumnSizes = malloc(maxSets * sizeof(int));

    int subset[numsSize];
    int subsetSize;

    for (int mask = 0; mask < maxSets; ++mask) {
        subsetSize = 0;
        bool isValid = true;

        for (int i = 0; i < numsSize; ++i) {
            if (mask & (1 << i)) {
                if (i > 0 && nums[i] == nums[i - 1] && !(mask & (1 << (i - 1)))) {
                    isValid = false;
                    break;
                }
                subset[subsetSize++] = nums[i];
            }
        }

        if (isValid) {
            result[*returnSize] = malloc(subsetSize * sizeof(int));
            memcpy(result[*returnSize], subset, subsetSize * sizeof(int));
            (*returnColumnSizes)[*returnSize] = subsetSize;
            (*returnSize)++;
        }
    }

    return result;
}   
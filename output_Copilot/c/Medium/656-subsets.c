/**https://leetcode.com/problems/subsets/ */
//Given an integer array nums of unique elements, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//Example 2:
//Input: nums = [0]
//Output: [[],[0]]
// 
//Constraints:
//	1 <= nums.length <= 10
//	-10 <= nums[i] <= 10
//	All the numbers of nums are unique.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(sizeof(int*) * (1 << numsSize));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (1 << numsSize));
    res[(*returnSize)] = (int*)malloc(sizeof(int));
    (*returnColumnSizes)[(*returnSize)] = 0;
    (*returnSize)++;
    for (int i = 0; i < numsSize; i++) {
        int size = 1 << i;
        for (int j = 0; j < size; j++) {
            res[(*returnSize)] = (int*)malloc(sizeof(int) * (i + 1));
            (*returnColumnSizes)[(*returnSize)] = i + 1;
            for (int k = 0; k < i; k++) {
                res[(*returnSize)][k] = res[j][k];
            }
            res[(*returnSize)][i] = nums[i];
            (*returnSize)++;
        }
    }
    return res;    
}
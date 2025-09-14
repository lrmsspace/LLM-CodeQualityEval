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
    int **result = (int **)malloc(numsSize * sizeof(int *));
    for (int i = 0; i < numsSize; i++) {
        result[i] = (int *)malloc(numsSize * sizeof(int));
        result[i][0] = nums[i];
    }
    for (int i = 1; i < numsSize; i++) {
        int j = 0;
        while (j < i) {
            int k = 0;
            while (k < numsSize) {
                if (result[j][k] != nums[i]) {
                    result[j * numsSize + k][i] = nums[i];
                }
                k++;
            }
            j++;
        }
    }
    *returnSize = (int)pow(numsSize, numsSize);
    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return result;
}   
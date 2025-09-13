/**https://leetcode.com/problems/3sum/ */
//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//Notice that the solution set must not contain duplicate triplets.
// 
//Example 1:
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]
//Explanation: 
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
//The distinct triplets are [-1,0,1] and [-1,-1,2].
//Notice that the order of the output and the order of the triplets does not matter.
//Example 2:
//Input: nums = [0,1,1]
//Output: []
//Explanation: The only possible triplet does not sum up to 0.
//Example 3:
//Input: nums = [0,0,0]
//Output: [[0,0,0]]
//Explanation: The only possible triplet sums up to 0.
// 
//Constraints:
//	3 <= nums.length <= 3000
//	-105 <= nums[i] <= 105
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int** result = (int**)malloc(numsSize * (numsSize - 1) / 2 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numsSize * (numsSize - 1) / 2 * sizeof(int));
    int k = 0;
    for (int i = 0; i < numsSize - 2; ++i) {
        for (int j = i + 1; j < numsSize - 1; ++j) {
            for (int m = j + 1; m < numsSize; ++m) {
                if (nums[i] + nums[j] + nums[m] == 0) {
                    result[k] = (int*)malloc(3 * sizeof(int));
                    result[k][0] = nums[i];
                    result[k][1] = nums[j];
                    result[k][2] = nums[m];
                    (*returnColumnSizes)[k] = 3;
                    ++k;
                    *returnSize += 1;
                }
            }
        }
    }
    return result;
}
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
    int i, j, k, sum, count = 0;
    int **result = (int **)malloc(sizeof(int *) * numsSize * numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);
    *returnSize = 0;
    if (numsSize < 3) {
        return result;
    }
    for (i = 0; i < numsSize - 2; i++) {
        for (j = i + 1; j < numsSize - 1; j++) {
            for (k = j + 1; k < numsSize; k++) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    int *temp = (int *)malloc(sizeof(int) * 3);
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];
                    result[count] = temp;
                    (*returnColumnSizes)[count] = 3;
                    count++;
                }
            }
        }
    }
    *returnSize = count;
    return result;    
}
/**https://leetcode.com/problems/4sum/ */
//Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
//	0 <= a, b, c, d < n
//	a, b, c, and d are distinct.
//	nums[a] + nums[b] + nums[c] + nums[d] == target
//You may return the answer in any order.
// 
//Example 1:
//Input: nums = [1,0,-1,0,-2,2], target = 0
//Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
//Example 2:
//Input: nums = [2,2,2,2,2], target = 8
//Output: [[2,2,2,2]]
// 
//Constraints:
//	1 <= nums.length <= 200
//	-109 <= nums[i] <= 109
//	-109 <= target <= 109
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    if (numsSize < 4) {
        return result;
    }
    int i, j, k, l, sum;
    int count = 0;
    int** temp = (int**)malloc(sizeof(int*) * 1000);
    for (i = 0; i < numsSize - 3; i++) {
        for (j = i + 1; j < numsSize - 2; j++) {
            for (k = j + 1; k < numsSize - 1; k++) {
                for (l = k + 1; l < numsSize; l++) {
                    sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        int* quadruplet = (int*)malloc(sizeof(int) * 4);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[k];
                        quadruplet[3] = nums[l];
                        temp[count] = quadruplet;
                        count++;
                    }
                }
            }
        }
    }
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (temp[i][0] == temp[j][0] && temp[i][1] == temp[j][1] && temp[i][2] == temp[j][2] && temp[i][3] == temp[j][3]) {
                break;
            }
        }
        if (j == count) {
            result[*returnSize] = temp[i];
            (*returnColumnSizes)[*returnSize] = 4;
            (*returnSize)++;
        }
    }
    return result;    
}
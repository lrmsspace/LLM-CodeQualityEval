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
    int** result = NULL;
    int resultSize = 0;
    int resultCapacity = 10;
    result = (int**)malloc(resultCapacity * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(resultCapacity * sizeof(int));
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1;
            int right = numsSize - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    int* quadruplet = (int*)malloc(4 * sizeof(int));
                    quadruplet[0] = nums[i];
                    quadruplet[1] = nums[j];
                    quadruplet[2] = nums[left];
                    quadruplet[3] = nums[right];
                    result[resultSize] = quadruplet;
                    (*returnColumnSizes)[resultSize] = 4;
                    resultSize++;
                    if (resultSize == resultCapacity) {
                        resultCapacity *= 2;
                        result = (int**)realloc(result, resultCapacity * sizeof(int*));
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, resultCapacity * sizeof(int));
                    }
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
                else if (sum < target) left++;
                else right--;
            }
        }
    }
    *returnSize = resultSize;
    return result;
    
}
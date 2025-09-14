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
    // Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);
    
    int** result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    
    // Iterate through the sorted array
    for (int i = 0; i < numsSize - 3; i++) {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        
        // Two-pointer technique to find the remaining two numbers
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            // Check if the sum equals to the target
            if (sum == target) {
                // Append the result to the array
                int* newResult = realloc(result, (*returnSize + 1) * sizeof(int*));
                if (!newResult)
                    return result;
                result = newResult;
                result[*returnSize] = malloc(4 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                result[*returnSize][3] = 0;
                (*returnSize)++;
                
                // Move the pointers to find the next valid pair
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            } else if (sum < target) {
                // Move the left pointer to the right
                left++;
            } else {
                // Move the right pointer to the left
                right--;
            }

        }
    }
    
    return result;

}
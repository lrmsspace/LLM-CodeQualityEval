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
    int** result = (int**)malloc(sizeof(int*) * 1000); // Allocate memory for 1000 triplets
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000); // Allocate memory for 1000 sizes
    int size = 0;
    qsort(nums, numsSize, sizeof(int), compare); // Sort the array in ascending order
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) // Skip duplicate numbers
            continue;
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result[size] = (int*)malloc(sizeof(int) * 3);
                result[size][0] = nums[i];
                result[size][1] = nums[left];
                result[size][2] = nums[right];
                (*returnColumnSizes)[size] = 3;
                size++;
                left++;
                right--;
                // Skip duplicate numbers
                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            } else if (sum < 0)
                left++;
            else
                right--;
        }
        // Skip duplicate numbers
        while (i < numsSize - 2 && nums[i] == nums[i + 1])
            i++;
    }
    *returnSize = size;
    return result;
}
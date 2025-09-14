/**https://leetcode.com/problems/largest-divisible-subset/ */
//Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
//	answer[i] % answer[j] == 0, or
//	answer[j] % answer[i] == 0
//If there are multiple solutions, return any of them.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: [1,2]
//Explanation: [1,3] is also accepted.
//Example 2:
//Input: nums = [1,2,4,8]
//Output: [1,2,4,8]
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 2 * 109
//	All the integers in nums are unique.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    // Sort the array in ascending order
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Create an array dp[] to store the length of the largest subset ending at each index
    int* dp = (int*)malloc(numsSize * sizeof(int));
    memset(dp, 0, numsSize * sizeof(int));
    
    // Initialize the largest subset length
    int maxLength = 0;
    
    // Initialize the index of the largest subset
    int maxIndex = 0;
    
    // Iterate through the array from left to right
    for (int i = 0; i < numsSize; i++) {
        // Initialize the length of the largest subset ending at index i as 1
        dp[i] = 1;
        
        // Iterate through the previous indices
        for (int j = 0; j < i; j++) {
            // If nums[i] is divisible by nums[j] and the length of the largest subset ending at index j plus 1 is greater than the current length, update the length
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        
        // If the current length is greater than the maximum length, update the maximum length and index
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            maxIndex = i;
        }
    }
    
    // Create a new array to store the largest subset
    int* result = (int*)malloc(maxLength * sizeof(int));
    
    // Iterate through the array from right to left, copying the elements to the result array
    for (int i = maxIndex, j = maxLength - 1; i >= 0 && j >= 0; i--) {
        if (dp[i] == j + 1 && nums[i] % nums[maxIndex] == 0) {
            result[j] = nums[i];
            j--;
        }
    }
    
    // Set the return size
    *returnSize = maxLength;
    
    // Return the largest subset
    return result;
    
}
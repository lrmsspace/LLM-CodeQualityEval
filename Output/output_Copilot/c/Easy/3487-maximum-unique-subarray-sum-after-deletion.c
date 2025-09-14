/*
 You are given an integer array nums.
 You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:
 All elements in the subarray are unique.
 The sum of the elements in the subarray is maximized.
 Return the maximum sum of such a subarray.
 Example 1:
 Input: nums = [1,2,3,4,5]
 Output: 15
 Explanation:
 Select the entire array without deleting any element to obtain the maximum sum.
 Example 2:
 Input: nums = [1,1,0,1,1]
 Output: 1
 Explanation:
 Delete the element nums[0] == 1, nums[1] == 1, nums[2] == 0, and nums[3] == 1. Select the entire array [1] to obtain the maximum sum.
 Example 3:
 Input: nums = [1,2,-1,-2,1,0,-1]
 Output: 3
 Explanation:
 Delete the elements nums[2] == -1 and nums[3] == -2, and select the subarray [2, 1] from [1, 2, 1, 0, -1] to obtain the maximum sum.
 Constraints:
 1 <= nums.length <= 100
 -100 <= nums[i] <= 100
*/

int maxSum(int* nums, int numsSize) {
    int maxSum = 0;
    int currentSum = 0;
    int seen[201] = {0}; // To track seen elements, range from -100 to 100

    for (int i = 0; i < numsSize; i++) {
        if (seen[nums[i] + 100] == 0) { // Check if the element is unique
            seen[nums[i] + 100] = 1; // Mark the element as seen
            currentSum += nums[i]; // Add to current sum
        } else {
            // If we encounter a duplicate, reset the current sum
            maxSum = (currentSum > maxSum) ? currentSum : maxSum; // Update max sum if needed
            currentSum = nums[i]; // Start new sum with the current element
            memset(seen, 0, sizeof(seen)); // Reset seen array
            seen[nums[i] + 100] = 1; // Mark the current element as seen
        }
    }

    // Final check to update maxSum after the loop ends
    maxSum = (currentSum > maxSum) ? currentSum : maxSum;

    return maxSum;
    
}
/*
 You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.
 Example 1:
 Input: nums = [1,4,3,3,2]
 Output: 2
 Explanation:
 The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
 The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
 Hence, we return 2.
 Example 2:
 Input: nums = [3,3,3,3]
 Output: 1
 Explanation:
 The strictly increasing subarrays of nums are [3], [3], [3], and [3].
 The strictly decreasing subarrays of nums are [3], [3], [3], and [3].
 Hence, we return 1.
 Example 3:
 Input: nums = [3,2,1]
 Output: 3
 Explanation:
 The strictly increasing subarrays of nums are [3], [2], and [1].
 The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].
 Hence, we return 3.
 Constraints:
 1 <= nums.length <= 50
 1 <= nums[i] <= 50
*/

int longestMonotonicSubarray(int* nums, int numsSize) {
    if (numsSize == 0) return 0; // Handle empty array case

    int maxLength = 1; // Initialize max length to 1
    int currentLength = 1; // Start with the first element

    // Check for strictly increasing subarray
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            currentLength++;
        } else {
            maxLength = (currentLength > maxLength) ? currentLength : maxLength;
            currentLength = 1; // Reset for next subarray
        }
    }
    maxLength = (currentLength > maxLength) ? currentLength : maxLength; // Final check for last subarray

    currentLength = 1; // Reset for strictly decreasing check

    // Check for strictly decreasing subarray
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            currentLength++;
        } else {
            maxLength = (currentLength > maxLength) ? currentLength : maxLength;
            currentLength = 1; // Reset for next subarray
        }
    }
    maxLength = (currentLength > maxLength) ? currentLength : maxLength; // Final check for last subarray

    return maxLength;
    
}
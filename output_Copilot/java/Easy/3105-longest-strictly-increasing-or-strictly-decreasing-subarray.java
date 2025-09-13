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

class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;

        int maxLength = 1;
        int currentLength = 1;

        // Check for strictly increasing subarrays
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currentLength++;
            } else {
                maxLength = Math.max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        maxLength = Math.max(maxLength, currentLength); // Final check for the last increasing subarray

        currentLength = 1; // Reset for decreasing check

        // Check for strictly decreasing subarrays
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                currentLength++;
            } else {
                maxLength = Math.max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        maxLength = Math.max(maxLength, currentLength); // Final check for the last decreasing subarray

        return maxLength;
        
    }
}
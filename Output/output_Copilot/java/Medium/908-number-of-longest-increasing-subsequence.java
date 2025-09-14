/**https://leetcode.com/problems/number-of-longest-increasing-subsequence/ */
//Given an integer array nums, return the number of longest increasing subsequences.
//Notice that the sequence has to be strictly increasing.
// 
//Example 1:
//Input: nums = [1,3,5,4,7]
//Output: 2
//Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
//Example 2:
//Input: nums = [2,2,2,2,2]
//Output: 5
//Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
// 
//Constraints:
//	1 <= nums.length <= 2000
//	-106 <= nums[i] <= 106
//	The answer is guaranteed to fit inside a 32-bit integer.
class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n]; // dp[i] stores the length of the longest increasing subsequence ending at index i
        int[] count = new int[n]; // count[i] stores the number of longest increasing subsequences ending at index i

        for (int i = 0; i < n; i++) {
            dp[i] = 1; // Each element is an increasing subsequence of length 1
            count[i] = 1; // Each element has one way to form a subsequence of length 1
        }

        int maxLength = 1; // Maximum length of increasing subsequence found so far

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) { // If nums[i] can extend the increasing subsequence ending at nums[j]
                    if (dp[j] + 1 > dp[i]) { // Found a longer increasing subsequence ending at nums[i]
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; // Count ways to form this new longest subsequence
                    } else if (dp[j] + 1 == dp[i]) { // Found another way to form the same length subsequence
                        count[i] += count[j];
                    }
                }
            }
            maxLength = Math.max(maxLength, dp[i]); // Update maximum length found so far
        }

        int totalCount = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLength) {
                totalCount += count[i]; // Sum counts of all longest increasing subsequences
            }
        }

        return totalCount;        
    }
}
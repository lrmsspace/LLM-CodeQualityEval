/*
 You are given an integer array nums.
 A subsequence sub of nums with length x is called valid if it satisfies:
 (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
 Return the length of the longest valid subsequence of nums.
 A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 Example 1:
 Input: nums = [1,2,3,4]
 Output: 4
 Explanation:
 The longest valid subsequence is [1, 2, 3, 4].
 Example 2:
 Input: nums = [1,2,1,1,2,1,2]
 Output: 6
 Explanation:
 The longest valid subsequence is [1, 2, 1, 2, 1, 2].
 Example 3:
 Input: nums = [1,3]
 Output: 2
 Explanation:
 The longest valid subsequence is [1, 3].
 Constraints:
 2 <= nums.length <= 2 * 105
 1 <= nums[i] <= 107
*/

class Solution {
    public int maximumLength(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][2];
        int max = 1;
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            dp[i][1] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] == nums[j]) {
                    dp[i][0] = dp[j][1] + 1;
                    break;
                }
            }
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] + nums[j] == 1) {
                    dp[i][1] = Math.max(dp[i][1], dp[j][0] + 1);
                }
            }
            max = Math.max(max, Math.max(dp[i][0], dp[i][1]));
        }
        return max;             
    }
}
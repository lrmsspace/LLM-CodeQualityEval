/*
 You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
 Return the maximum possible length of a good subsequence of nums.
 Example 1:
 Input: nums = [1,2,1,1,3], k = 2
 Output: 4
 Explanation:
 The maximum length subsequence is [1,2,1,1,3].
 Example 2:
 Input: nums = [1,2,3,4,5,1], k = 0
 Output: 2
 Explanation:
 The maximum length subsequence is [1,2,3,4,5,1].
 Constraints:
 1 <= nums.length <= 5 * 103
 1 <= nums[i] <= 109
 0 <= k <= min(50, nums.length)
*/

class Solution {
    public int maximumLength(int[] nums, int k) {
        int n = nums.length;
        int[][] dp = new int[n][k + 2];
        int res = 1;
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            for (int j = 0; j <= k; j++) {
                dp[i][j + 1] = 1;
                if (i > 0) {
                    for (int p = 0; p < i; p++) {
                        if (nums[p] == nums[i]) {
                            dp[i][j + 1] = Math.max(dp[i][j + 1], dp[p][j] + 1);
                        }
                    }
                }
                res = Math.max(res, dp[i][j + 1]);
            }
        }
        return res;        
    }
}
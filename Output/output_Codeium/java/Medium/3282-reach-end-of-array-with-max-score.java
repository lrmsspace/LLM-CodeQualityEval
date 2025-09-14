/*
 You are given an integer array nums of length n.
 Your goal is to start at index 0 and reach index n - 1. You can only jump to indices greater than your current index.
 The score for a jump from index i to index j is calculated as (j - i) * nums[i].
 Return the maximum possible total score by the time you reach the last index.
 Example 1:
 Input: nums = [1,3,1,5]
 Output: 7
 Explanation:
 First, jump to index 1 and then jump to the last index. The final score is 1 * 1 + 2 * 3 = 7.
 Example 2:
 Input: nums = [4,3,1,3,2]
 Output: 16
 Explanation:
 Jump directly to the last index. The final score is 4 * 4 = 16.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 105
*/

class Solution {
    public long findMaximumScore(List<Integer> nums) {
        int n = nums.size();
        long[] dp = new long[n];
        dp[0] = nums.get(0);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = Math.max(dp[i], dp[j] + (long)(i - j) * nums.get(i));
            }
        }
        return dp[n - 1];
    }
}
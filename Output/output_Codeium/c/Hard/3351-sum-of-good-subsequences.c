/*
 You are given an integer array nums. A good subsequence is defined as a subsequence of nums where the absolute difference between any two consecutive elements in the subsequence is exactly 1.
 Return the sum of all possible good subsequences of nums.
 Since the answer may be very large, return it modulo 109 + 7.
 Note that a subsequence of size 1 is considered good by definition.
 Example 1:
 Input: nums = [1,2,1]
 Output: 14
 Explanation:
 Good subsequences are: [1], [2], [1], [1,2], [2,1], [1,2,1].
 The sum of elements in these subsequences is 14.
 Example 2:
 Input: nums = [3,4,5]
 Output: 40
 Explanation:
 Good subsequences are: [3], [4], [5], [3,4], [4,5], [3,4,5].
 The sum of elements in these subsequences is 40.
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i] <= 105
*/

int sumOfGoodSubsequences(int* nums, int numsSize) {
    int MOD = 1e9 + 7;
    int n = numsSize;
    int dp[n][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = dp[0][1] = nums[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1] + nums[i]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1] + nums[i]) % MOD;
    }
    return (dp[n - 1][0] + dp[n - 1][1]) % MOD;
}
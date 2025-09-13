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
    int MOD = 1000000007;
    int dp[105][2] = {0};
    dp[0][0] = 1;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || nums[i] - nums[j - 1] == 1) {
                dp[i + 1][0] = (dp[i + 1][0] + dp[j][0]) % MOD;
                dp[i + 1][1] = (dp[i + 1][1] + dp[j][1]) % MOD;
            }
        }
    }
    
    return (dp[numsSize][0] + dp[numsSize][1]) % MOD;
    
}
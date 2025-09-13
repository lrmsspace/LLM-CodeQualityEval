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
    const int MOD = 1000000007;
    long long dp[100001] = {0};
    long long total = 0;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        dp[num] = (dp[num] + 1) % MOD; // count the single element subsequence
        if (num > 0) {
            dp[num] = (dp[num] + dp[num - 1]) % MOD; // add subsequences ending with num-1
        }
        if (num < 100000) {
            dp[num] = (dp[num] + dp[num + 1]) % MOD; // add subsequences starting with num+1
        }
        total = (total + dp[num]) % MOD; // accumulate the total sum
    }

    return (int)total;    
}
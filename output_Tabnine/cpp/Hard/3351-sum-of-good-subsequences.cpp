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

class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(1 << n, 0);
        dp[0] = 1;
        long long mod = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            for (int mask = (1 << i) - 1; mask >= 0; mask--) {
                if (nums[i] - 1 <= nums[__builtin_popcount(mask)]) {
                    dp[mask | (1 << i)] += dp[mask];
                    dp[mask | (1 << i)] %= mod;
                }
            }
        }
        
        long long ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            ans += dp[mask];
            ans %= mod;
        }
        
        return ans;
        
    }
};
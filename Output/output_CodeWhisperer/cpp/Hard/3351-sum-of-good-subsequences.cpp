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
        int mod = 1e9 + 7;
        vector<int> freq(101, 0);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        vector<int> dp(101, 0);
        dp[0] = 1;
        for (int i = 1; i <= 100; i++) {
            if (freq[i] == 0) continue;
            vector<int> new_dp(101, 0);
            for (int j = 0; j <= 100; j++) {
                new_dp[j] = (new_dp[j] + dp[j]) % mod;
                if (j + i <= 100) {
                    new_dp[j + i] = (new_dp[j + i] + dp[j] * freq[i]) % mod;
                }
            }
            dp = new_dp;
        }
        int ans = 0;
        for (int i = 1; i <= 100; i++) {
            ans = (ans + dp[i] * freq[i]) % mod;
        }
        for (int i = 1; i <= 100; i++) {
            if (freq[i] > 1) {
                ans = (ans + 1) % mod;
                break;
            }
        }
        return ans;
    }
};
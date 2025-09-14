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
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // dp[i] will store the sum of all good subsequences ending with nums[i]
        vector<long long> dp(n, 0);
        
        // Initialize the dp array with the element itself (each element is a good subsequence)
        for (int i = 0; i < n; ++i) {
            dp[i] = nums[i];
        }
        
        // Calculate the sum of good subsequences
        long long totalSum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (abs(nums[i] - nums[j]) == 1) {  // Check if the subsequence is good
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
            }
            totalSum = (totalSum + dp[i]) % MOD;
        }
        
        return totalSum;

    }
};
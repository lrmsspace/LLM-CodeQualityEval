/**https://leetcode.com/problems/split-array-largest-sum/ */
//Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
//Return the minimized largest sum of the split.
//A subarray is a contiguous part of the array.
// 
//Example 1:
//Input: nums = [7,2,5,10,8], k = 2
//Output: 18
//Explanation: There are four ways to split nums into two subarrays.
//The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
//Example 2:
//Input: nums = [1,2,3,4,5], k = 2
//Output: 9
//Explanation: There are four ways to split nums into two subarrays.
//The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	0 <= nums[i] <= 106
//	1 <= k <= min(50, nums.length)
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INT_MAX));
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                for (int l = 0; l < i; ++l) {
                    dp[i][j] = min(dp[i][j], max(dp[l][j - 1], prefix[i] - prefix[l]));
                }
            }
        }
        
        return dp[n][k];
        
    }
};
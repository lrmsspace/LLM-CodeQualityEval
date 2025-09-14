/**https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/ */
//Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
//Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
// 
//Example 1:
//Input: nums = [1,2,1,2,6,7,5,1], k = 2
//Output: [0,3,5]
//Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
//We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
//Example 2:
//Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
//Output: [0,2,4]
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i] < 216
//	1 <= k <= floor(nums.length / 3)
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        vector<vector<int>> dp(n, vector<int>(4, 0));
        for (int i = 0; i < n - k + 1; ++i) {
            int sum = prefixSum[i + k] - prefixSum[i];
            if (i == 0 || sum > dp[i - 1][0]) {
                dp[i][0] = sum;
                dp[i][1] = i;
            } else {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
            }
        }
        for (int i = k; i < n - k + 1; ++i) {
            int sum = prefixSum[i + k] - prefixSum[i] + dp[i - k][0];
            if (sum > dp[i - 1][2]) {
                dp[i][2] = sum;
                dp[i][3] = dp[i - k][1];
            } else {
                dp[i][2] = dp[i - 1][2];
                dp[i][3] = dp[i - 1][3];
            }
        }
        vector<int> res(3);
        res[0] = dp[n - k][1];
        res[1] = dp[n - k][3];
        res[2] = dp[n - k][1] + k;
        return res;
    }
};
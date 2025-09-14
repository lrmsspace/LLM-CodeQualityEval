/*
 You are given an integer array nums and two integers, k and m.
 Return the maximum sum of k non-overlapping subarrays of nums, where each subarray has a length of at least m.
 Example 1:
 Input: nums = [1,2,-1,3,3,4], k = 2, m = 2
 Output: 13
 Explanation:
 The optimal choice is:
 Subarray nums[3..5] with sum 3 + 3 + 4 = 10 (length is 3 >= m).
 Subarray nums[0..1] with sum 1 + 2 = 3 (length is 2 >= m).
 The total sum is 10 + 3 = 13.
 Example 2:
 Input: nums = [-10,3,-1,-2], k = 4, m = 1
 Output: -10
 Explanation:
 The optimal choice is choosing each element as a subarray. The output is (-10) + 3 + (-1) + (-2) = -10.
 Constraints:
 1 <= nums.length <= 2000
 -104 <= nums[i] <= 104
 1 <= k <= floor(nums.length / m)
 1 <= m <= 3
*/

class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MIN));
        dp[0][0] = 0;

        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                int currSum = 0;
                for (int len = 1; len <= m && j + len - 1 < n; len++) {
                    currSum += nums[j + len - 1];
                    dp[i][j + len] = max(dp[i][j + len], dp[i - 1][j] + currSum);
                }
            }
        }

        int maxSum = INT_MIN;
        for (int i = 0; i <= n; i++) {
            maxSum = max(maxSum, dp[k][i]);
        }

        return maxSum;
    }
};
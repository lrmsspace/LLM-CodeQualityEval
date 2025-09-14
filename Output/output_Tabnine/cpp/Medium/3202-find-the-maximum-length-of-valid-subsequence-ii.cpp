/*
 You are given an integer array nums and a positive integer k.
 A subsequence sub of nums with length x is called valid if it satisfies:
 (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
 Return the length of the longest valid subsequence of nums.
 Example 1:
 Input: nums = [1,2,3,4,5], k = 2
 Output: 5
 Explanation:
 The longest valid subsequence is [1, 2, 3, 4, 5].
 Example 2:
 Input: nums = [1,4,2,3,1,4], k = 3
 Output: 4
 Explanation:
 The longest valid subsequence is [1, 4, 1, 4].
 Constraints:
 2 <= nums.length <= 103
 1 <= nums[i] <= 107
 1 <= k <= 103
*/

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 0));   
        dp[0][nums[0] % k] = 1;
        int maxLen = 1;
        for (int i = 1; i < n; i++) {

            for (int j = 0; j < k; j++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][(j - nums[i] % k + k) % k] + 1);
                maxLen = max(maxLen, dp[i][j]);
            }

            // If nums[i] is the same as nums[i - 1], skip it
            if (nums[i] == nums[i - 1]) {
                for (int j = 0; j < k; j++) {
                    dp[i][j] = max(dp[i][j], dp[i - 2][(j - nums[i - 1] % k + k) % k] + 2);
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen;
        
    }
};
/*
 You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
 Return the maximum possible length of a good subsequence of nums.
 Example 1:
 Input: nums = [1,2,1,1,3], k = 2
 Output: 4
 Explanation:
 The maximum length subsequence is [1,2,1,1,3].
 Example 2:
 Input: nums = [1,2,3,4,5,1], k = 0
 Output: 2
 Explanation:
 The maximum length subsequence is [1,2,3,4,5,1].
 Constraints:
 1 <= nums.length <= 5 * 103
 1 <= nums[i] <= 109
 0 <= k <= min(50, nums.length)
*/

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 1));
        unordered_map<int, int> mp;
        int res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = mp[nums[i]] + 1;
                if (j > 0) {
                    for (int l = 0; l < i; l++) {
                        if (nums[l] != nums[i]) {
                            dp[i][j] = max(dp[i][j], dp[l][j - 1] + 1);
                        }
                    }
                }
                mp[nums[i]] = max(mp[nums[i]], dp[i][j]);
                res = max(res, dp[i][j]);
            }
        }
        return res;

    }
};
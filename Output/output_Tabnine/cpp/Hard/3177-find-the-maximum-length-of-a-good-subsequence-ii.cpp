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

        vector<int> dp(nums.size(), 1);
        int maxLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i]!= nums[j] && dp[i] <= dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen + k; // add k to the maximum length to account for the additional indices that could be added in the good subsequence.    
        
    }
};
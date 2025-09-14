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
 1 <= nums.length <= 500
 1 <= nums[i] <= 109
 0 <= k <= min(nums.length, 25)
*/

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i] + 1; // Include current element
            if (lastIndex.find(nums[i]) != lastIndex.end()) {
                int prevIndex = lastIndex[nums[i]];
                int diff = i - prevIndex - 1;
                if (diff <= k) {
                    dp[i + 1] = max(dp[i + 1], dp[prevIndex + 1] + 1);
                }
            }
            lastIndex[nums[i]] = i;
        }

        return dp[n];        
    }
};
/**https://leetcode.com/problems/constrained-subsequence-sum/ */
//Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.
//A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.
// 
//Example 1:
//Input: nums = [10,2,-10,5,20], k = 2
//Output: 37
//Explanation: The subsequence is [10, 2, 5, 20].
//Example 2:
//Input: nums = [-1,-2,-3], k = 1
//Output: -1
//Explanation: The subsequence must be non-empty, so we choose the largest number.
//Example 3:
//Input: nums = [10,-2,-10,-5,20], k = 2
//Output: 23
//Explanation: The subsequence is [10, -2, -5, 20].
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	-104 <= nums[i] <= 104
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
            if (!dq.empty()) {
                dp[i] = max(dp[i], dp[dq.front()] + nums[i]);
            }
            res = max(res, dp[i]);
            while (!dq.empty() && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }
            if (dp[i] > 0) {
                dq.push_back(i);
            }
            if (i - dq.front() + 1 > k) {
                dq.pop_front();
            }
        }
        return res;
    }
};
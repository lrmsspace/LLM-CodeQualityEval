/**https://leetcode.com/problems/partition-to-k-equal-sum-subsets/ */
//Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
// 
//Example 1:
//Input: nums = [4,3,2,3,5,2,1], k = 4
//Output: true
//Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
//Example 2:
//Input: nums = [1,2,3,4], k = 3
//Output: false
// 
//Constraints:
//	1 <= k <= nums.length <= 16
//	1 <= nums[i] <= 104
//	The frequency of each element is in the range [1, 4].
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        vector<bool> dp(1 << nums.size(), false);
        dp[0] = true;
        vector<int> total(1 << nums.size(), 0);
        for (int state = 0; state < (1 << nums.size()); state++) {
            if (!dp[state]) {
                continue;
            }
            for (int i = 0; i < nums.size(); i++) {
                if ((state & (1 << i)) != 0) {
                    continue;
                }
                int nextState = state | (1 << i);
                if (dp[nextState]) {
                    continue;
                }
                if ((total[state] + nums[i]) % target == 0) {
                    dp[nextState] = true;
                }
                total[nextState] = (total[state] + nums[i]) % target;
            }
        }
        return dp[(1 << nums.size()) - 1];     
    }
};
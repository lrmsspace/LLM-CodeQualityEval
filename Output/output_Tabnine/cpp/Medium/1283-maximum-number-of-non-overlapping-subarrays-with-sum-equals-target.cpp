/**https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/ */
//Given an array nums and an integer target, return the maximum number of non-empty non-overlapping subarrays such that the sum of values in each subarray is equal to target.
// 
//Example 1:
//Input: nums = [1,1,1,1,1], target = 2
//Output: 2
//Explanation: There are 2 non-overlapping subarrays [1,1,1,1,1] with sum equals to target(2).
//Example 2:
//Input: nums = [-1,3,5,1,4,2,-9], target = 6
//Output: 2
//Explanation: There are 3 subarrays with sum equal to 6.
//([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.
// 
//Constraints:
//	1 <= nums.length <= 105
//	-104 <= nums[i] <= 104
//	0 <= target <= 106
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0 && pre[i] - pre[j] <= target; j--) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        
        return res;
        
    }
};
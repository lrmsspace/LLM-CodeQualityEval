/**https://leetcode.com/problems/house-robber-iv/ */
//There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.
//The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.
//You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.
//You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.
//Return the minimum capability of the robber out of all the possible ways to steal at least k houses.
// 
//Example 1:
//Input: nums = [2,3,5,9], k = 2
//Output: 5
//Explanation: 
//There are three ways to rob at least 2 houses:
//- Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
//- Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
//- Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
//Therefore, we return min(5, 9, 9) = 5.
//Example 2:
//Input: nums = [2,7,9,3,1], k = 2
//Output: 2
//Explanation: There are 7 ways to rob the houses. The way which leads to minimum capability is to rob the house at index 0 and 4. Return max(nums[0], nums[4]) = 2.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 109
//	1 <= k <= (nums.length + 1)/2
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return min(nums[0], nums[1]);
        if (k == 1) return *min_element(nums.begin(), nums.end());
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int res = dp[n - 1];
        dp[n - 1] = nums[n - 1];
        dp[n - 2] = max(nums[n - 1], nums[n - 2]);
        for (int i = n - 3; i >= 0; i--) {
            dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            if (i == 0) {
                res = min(res, dp[i + 1]);
            } else if (i == n - 2) {
                res = min(res, dp[i]);
            } else {
                res = min(res, max(dp[i], dp[i + 1]));
            }
        }
        return res;        
    }
};
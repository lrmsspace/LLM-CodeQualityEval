/**https://leetcode.com/problems/burst-balloons/ */
//You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
//If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
//Return the maximum coins you can collect by bursting the balloons wisely.
// 
//Example 1:
//Input: nums = [3,1,5,8]
//Output: 167
//Explanation:
//nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
//coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
//Example 2:
//Input: nums = [1,5]
//Output: 10
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 300
//	0 <= nums[i] <= 100
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int length = 1; length <= n; ++length) {
            for (int left = 0; left <= n - length; ++left) {
                int right = left + length - 1;
                for (int i = left; i <= right; ++i) {
                    dp[left][right] = max(dp[left][right], dp[left][i-1] + dp[i+1][right] + nums[left-1]*nums[i]*nums[right+1]);
                }
            }
        }
        return dp[1][n-1];
    }
};
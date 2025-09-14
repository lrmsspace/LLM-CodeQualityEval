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
int maxCoins(int* nums, int numsSize) {
    int dp[numsSize + 2][numsSize + 2];
    memset(dp, 0, sizeof(dp));
    for (int length = 1; length <= numsSize; ++length) {
        for (int left = 0; left <= numsSize - length; ++left) {
            int right = left + length - 1;
            for (int i = left; i <= right; ++i) {
                int coins = nums[i] * (left > 0 ? nums[left - 1] : 1) * (right < numsSize - 1 ? nums[right + 1] : 1);
                dp[left][right] = max(dp[left][right], dp[left][i - 1] + coins + dp[i + 1][right]);
            }
        }
    }
    return dp[0][numsSize - 1];
}
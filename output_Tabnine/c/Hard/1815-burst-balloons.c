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
    int n = numsSize;
    int* dp = (int*)malloc(sizeof(int) * (n + 2));
    int* temp = (int*)malloc(sizeof(int) * (n + 2));
    
    memset(dp, 0, sizeof(int) * (n + 2));
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 2; j <= n + 1; j++) {
            for (int k = i + 1; k < j; k++) {
                dp[i] = fmax(dp[i], nums[i] * nums[k] * nums[j - 1] + dp[i + 1] + dp[k]);
            }
        }
    }
    
    return dp[0];
    
}
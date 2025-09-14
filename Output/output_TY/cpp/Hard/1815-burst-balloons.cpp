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
        vector<int> v(n+2,1);
        for(int i=1;i<=n;i++){
            v[i] = nums[i-1];
        }
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int ans = INT_MIN;
                for(int k=i;k<=j;k++){
                    int cost = v[i-1]*v[k]*v[j+1] + dp[i][k-1] + dp[k+1][j];
                    ans = max(ans,cost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
};
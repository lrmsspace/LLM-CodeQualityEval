/**https://leetcode.com/problems/maximize-score-after-n-operations/ */
//You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.
//In the ith operation (1-indexed), you will:
//	Choose two elements, x and y.
//	Receive a score of i * gcd(x, y).
//	Remove x and y from nums.
//Return the maximum score you can receive after performing n operations.
//The function gcd(x, y) is the greatest common divisor of x and y.
// 
//Example 1:
//Input: nums = [1,2]
//Output: 1
//Explanation: The optimal choice of operations is:
//(1 * gcd(1, 2)) = 1
//Example 2:
//Input: nums = [3,4,6,8]
//Output: 11
//Explanation: The optimal choice of operations is:
//(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
//Example 3:
//Input: nums = [1,2,3,4,5,6]
//Output: 14
//Explanation: The optimal choice of operations is:
//(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
// 
//Constraints:
//	1 <= n <= 7
//	nums.length == 2 * n
//	1 <= nums[i] <= 106
class Solution {
public:
    int maxScore(vector<int>& nums) {    
        int n = nums.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];
        for (int i = 0; i < n - 1; i++)
            dp[i][i + 1] = nums[i] * nums[i + 1];
        for (int len = 3; len <= n; len++)
            for (int i = 0; i + len - 1 < n; i++)
                for (int j = i + 1; j + len - 1 < n; j++)
                    dp[i][j + len - 1] = max(dp[i][j] + dp[j][j + len - 1] + nums[i] * nums[j + len - 1], dp[i][j + len - 1]);
                    
        return dp[0][n - 1];
    }
};
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
    public int maxScore(int[] nums) {
        int n = nums.length;
        int[][] gcd = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                gcd[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int[] dp = new int[1 << n];
        for (int i = 0; i < dp.length; i++) {
            dp[i] = -1;
        }
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1) continue;
            int ones = Integer.bitCount(mask);
            int pairs = ones / 2;
            if (ones % 2 == 1) continue;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (((mask >> i) & 1) == 1 || ((mask >> j) & 1) == 1) continue;
                    int nextMask = mask | (1 << i) | (1 << j);
                    dp[nextMask] = Math.max(dp[nextMask], dp[mask] + (pairs + 1) * gcd[i][j]);
                }
            }
        }
        return dp[(1 << n) - 1];      
    }
}
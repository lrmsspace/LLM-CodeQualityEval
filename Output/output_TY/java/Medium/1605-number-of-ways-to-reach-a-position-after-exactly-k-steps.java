/**https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/ */
//You are given two positive integers startPos and endPos. Initially, you are standing at position startPos on an infinite number line. With one step, you can move either one position to the left, or one position to the right.
//Given a positive integer k, return the number of different ways to reach the position endPos starting from startPos, such that you perform exactly k steps. Since the answer may be very large, return it modulo 109 + 7.
//Two ways are considered different if the order of the steps made is not exactly the same.
//Note that the number line includes negative integers.
// 
//Example 1:
//Input: startPos = 1, endPos = 2, k = 3
//Output: 3
//Explanation: We can reach position 2 from 1 in exactly 3 steps in three ways:
//- 1 -> 2 -> 3 -> 2.
//- 1 -> 2 -> 1 -> 2.
//- 1 -> 0 -> 1 -> 2.
//It can be proven that no other way is possible, so we return 3.
//Example 2:
//Input: startPos = 2, endPos = 5, k = 10
//Output: 0
//Explanation: It is impossible to reach position 5 from position 2 in exactly 10 steps.
// 
//Constraints:
//	1 <= startPos, endPos, k <= 1000
class Solution {
    public int numberOfWays(int startPos, int endPos, int k) {
        int dp[][] = new int[k + 1][k + 1];
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(startPos, endPos, k, dp);
    }

    public int solve(int startPos, int endPos, int k, int dp[][]) {
        if (k == 0) {
            if (startPos == endPos) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dp[k][startPos] != -1) {
            return dp[k][startPos];
        }
        return dp[k][startPos] = solve(startPos + 1, endPos, k - 1, dp) + solve(startPos - 1, endPos, k - 1, dp);
    }
}
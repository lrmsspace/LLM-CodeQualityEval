/**https://leetcode.com/problems/ugly-number-ii/ */
//An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
//Given an integer n, return the nth ugly number.
// 
//Example 1:
//Input: n = 10
//Output: 12
//Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
//Example 2:
//Input: n = 1
//Output: 1
//Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
// 
//Constraints:
//	1 <= n <= 1690
class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n+1];
        dp[1] = 1;
        int i2 = 1, i3 = 1, i5 = 1;
        for(int i = 2; i <= n; i++){
            int min = Math.min(Math.min(dp[i2]*2, dp[i3]*3), dp[i5]*5);
            dp[i] = min;
            if(min == dp[i2]*2) i2++;
            if(min == dp[i3]*3) i3++;
            if(min == dp[i5]*5) i5++;
        }
        return dp[n];
    }
}
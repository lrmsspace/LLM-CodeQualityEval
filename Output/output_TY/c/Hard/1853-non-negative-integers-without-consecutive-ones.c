/**https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/ */
//Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.
// 
//Example 1:
//Input: n = 5
//Output: 5
//Explanation:
//Here are the non-negative integers <= 5 with their corresponding binary representations:
//0 : 0
//1 : 1
//2 : 10
//3 : 11
//4 : 100
//5 : 101
//Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
//Example 2:
//Input: n = 1
//Output: 2
//Example 3:
//Input: n = 2
//Output: 3
// 
//Constraints:
//	1 <= n <= 109
int findIntegers(int n){
    int dp[32][2], res = 0;
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < 32; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
   for (int i = 30; i >= 0; i--) {
       int bit = (n >> i) & 1;
       res += dp[i][bit];
   }
   return res;
}
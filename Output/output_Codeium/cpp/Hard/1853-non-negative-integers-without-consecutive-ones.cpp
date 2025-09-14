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
class Solution {
public:
    int findIntegers(int n) {
        int dp[32] = {1, 2};
        for (int i = 2; i < 32; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            result += (n + 1) / (1 << i) * dp[i];
            if (n + 1 & (1 << i)) {
                result -= (1 << i) - dp[i - 1];
            }
        }
        return result;
    }
};
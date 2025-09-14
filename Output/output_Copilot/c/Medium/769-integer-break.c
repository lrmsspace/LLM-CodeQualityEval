/**https://leetcode.com/problems/integer-break/ */
//Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
//Return the maximum product you can get.
// 
//Example 1:
//Input: n = 2
//Output: 1
//Explanation: 2 = 1 + 1, 1 × 1 = 1.
//Example 2:
//Input: n = 10
//Output: 36
//Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
// 
//Constraints:
//	2 <= n <= 58
int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n == 4) return 4;
    if (n == 5) return 6;
    if (n == 6) return 9;
    return 3 * integerBreak(n - 3);    
}
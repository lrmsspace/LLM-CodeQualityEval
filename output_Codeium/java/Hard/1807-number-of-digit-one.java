/**https://leetcode.com/problems/number-of-digit-one/ */
//Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
// 
//Example 1:
//Input: n = 13
//Output: 6
//Example 2:
//Input: n = 0
//Output: 0
// 
//Constraints:
//	0 <= n <= 109
class Solution {
    public int countDigitOne(int n) {
        int res = 0;
        for (long i = 1; i <= n; i *= 10) {
            long div = i * 10;
            res += (n / div) * i + Math.min(Math.max(n % div - i + 1, 0), i);
        }
        return res;
    }
}
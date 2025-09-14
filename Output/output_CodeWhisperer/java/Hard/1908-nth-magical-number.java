/**https://leetcode.com/problems/nth-magical-number/ */
//A positive integer is magical if it is divisible by either a or b.
//Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 1, a = 2, b = 3
//Output: 2
//Example 2:
//Input: n = 4, a = 2, b = 3
//Output: 6
// 
//Constraints:
//	1 <= n <= 109
//	2 <= a, b <= 4 * 104
class Solution {
    public int nthMagicalNumber(int n, int a, int b) {
        long A = a, B = b, tmp;
        long mod = (long)1e9 + 7;
        while (b > 0) {
            tmp = a;
            a = b;
            b = tmp % b;
        }
        while (a % b != 0) {
            tmp = a;
            a = b;
            b = tmp % b;
        }
        long l = 2, r = (long)1e17, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (m / a + m / b - m / (a * b / a) >= n) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return (int)(l % mod);       
    }
}
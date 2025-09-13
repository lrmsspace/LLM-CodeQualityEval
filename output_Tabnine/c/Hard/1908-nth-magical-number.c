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
int nthMagicalNumber(int n, int a, int b) {
    long lcm = lcm(a, b);
    long res = 0;
    long mod = 1000000007;
    
    for (int i = 1; i <= n; i++) {
        long left = (a * (n / a) - (n / lcm)) / 2;
        long right = (b * (n / b) - (n / lcm)) / 2;
        res = (res + left + right) % mod;
    }
    
    return (int)res;
    
}
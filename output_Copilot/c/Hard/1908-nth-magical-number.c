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
    int mod = 1000000007;
    long long lcm = a / __gcd(a, b) * b;
    long long l = 2, r = 1e18;
    while (l < r) {
        long long m = l + (r - l) / 2;
        if (m / a + m / b - m / lcm < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l % mod;    
}
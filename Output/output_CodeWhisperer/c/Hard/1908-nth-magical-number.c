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
    int MOD = 1000000007;

    int lcm = a * b / gcd(a, b);

    long long left = 2, right = 2000000000;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        long long count = mid / a + mid / b - mid / lcm;

        if (count >= n) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return (right + 1) % MOD;
    
}
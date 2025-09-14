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
public:
    int nthMagicalNumber(int n, int a, int b) {
        int mod = 1e9 + 7;
        long long l = min(a, b);
        long long r = (long long)min(a, b) * n;
        int c = lcm(a, b);
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long cnt = mid / a + mid / b - mid / c;
            if (cnt >= n) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return (r + 1) % mod;      
    }
};
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
        long A = a, B = b;
        long L = 2, R = (long)1e18;
        while (L < R) {
            long mid = (L + R) / 2;
            if (mid / A + mid / B - mid / lcm(A, B) >= n) {
                R = mid;
            } else {
                L = mid + 1;
            }
        }
        return (int)(L % (1e9 + 7));
        
    }
    
    private long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
    
    private long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
        
}
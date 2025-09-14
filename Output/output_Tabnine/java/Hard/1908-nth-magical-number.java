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
        long lcm = (long)a * b / gcd(a, b);
        long low = Math.min(a, b);
        long high = lcm * n;
        
        while (low <= high) {
            long mid = low + (high - low) / 2;
            long count = mid / a + mid / b - mid / lcm;
            if (count >= n) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return (int)((low / a + low / b - low / lcm) % (1000000007));
        
    }
}
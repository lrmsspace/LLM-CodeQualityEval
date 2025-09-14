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
        long long mod = 1e9 + 7;
        long long lcm = (long long)a * b / gcd(a, b);
        long long low = min(a, b) * (n - 1) + 1;
        long long high = lcm * (n - 1);
        long long ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long cnt = mid / a + mid / b - mid / lcm;
            
            if (cnt >= n) {
                ans = mid % mod;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
        
    }
};
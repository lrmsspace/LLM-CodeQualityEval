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
        const int MOD = 1e9 + 7;
        auto gcd = [](long long x, long long y) {
            while (y != 0) {
                long long temp = y;
                y = x % y;
                x = temp;
            }
            return x;
        };
        
        auto lcm = [&](long long x, long long y) {
            return x / gcd(x, y) * y;
        };
        
        long long ab = lcm(a, b);
        
        auto countMagicalNumbers = [&](long long x) {
            return x / a + x / b - x / ab;
        };
        
        long long left = 1, right = 1e18, answer = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (countMagicalNumbers(mid) < n) {
                left = mid + 1;
            } else {
                answer = mid;
                right = mid - 1;
            }
        }
        
        return answer % MOD;

    }
};
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
/**
 * @param {number} n
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var nthMagicalNumber = function(n, a, b) {
    const MOD = 10 ** 9 + 7;
    const lcm = (a * b) / gcd(a, b);
    const half = n / 2;
    
    let left = Math.min(a, b);
    let right = lcm * half;
    
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        const count = Math.floor(mid / a) + Math.floor(mid / b) - Math.floor(mid / lcm);
        
        if (count === n - 1) {
            return (mid % MOD);
        } else if (count < n - 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
    
};
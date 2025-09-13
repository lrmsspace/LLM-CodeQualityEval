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
    let lcm = a * b / gcd(a, b);
    let count = Math.floor(lcm / a) + Math.floor(lcm / b) - 1;
    let res = (n - 1) / count * lcm % (10**9 + 7);
    res += Math.min((n - 1) % count * a % (10**9 + 7), (n - 1) % count * b % (10**9 + 7));
    return res % (10**9 + 7);
    
    function gcd(a, b) {
        return b ? gcd(b, a % b) : a;
    }
};
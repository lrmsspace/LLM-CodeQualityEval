/**https://leetcode.com/problems/mirror-reflection/ */
//There is a special square room with mirrors on each of the four walls. Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.
//The square room has walls of length p and a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor.
//Given the two integers p and q, return the number of the receptor that the ray meets first.
//The test cases are guaranteed so that the ray will meet a receptor eventually.
// 
//Example 1:
//Input: p = 2, q = 1
//Output: 2
//Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.
//Example 2:
//Input: p = 3, q = 1
//Output: 1
// 
//Constraints:
//	1 <= q <= p <= 1000
/**
 * @param {number} p
 * @param {number} q
 * @return {number}
 */
var mirrorReflection = function(p, q) {
    let gcd = (a, b) => b === 0 ? a : gcd(b, a % b);
    let g = gcd(p, q);
    let pq2 = p / g / 2;
    let q2 = q / g / 2;
    if (pq2 % 1 === 0) return 2;
    if (q2 % 1 === 0) return 0;
    return 1;
};
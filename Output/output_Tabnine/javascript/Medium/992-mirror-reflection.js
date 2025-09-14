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
    // The mirror reflection pattern repeats every 2p units (p-1 mirrors and 1 wall).
    // When the ray meets the east wall, it bounces off the wall and continues moving to the right.
    // When the ray meets the southwest corner, it bounces off the wall and continues moving to the left.
    // We can find the reflection point by dividing the ray's position by 2p and taking the integer part of the result.
    // If the result is an odd number, the ray meets the southwest corner; otherwise, it meets the east wall.
    // We can determine the receptor by checking if the reflection point is odd or even.
    // If the reflection point is odd, the ray meets receptor 2; otherwise, it meets receptor 1.
    return (q % (2 * p - 2) + 2 * p - 2) % (2 * p) === 0? 2 : 1;
    
};
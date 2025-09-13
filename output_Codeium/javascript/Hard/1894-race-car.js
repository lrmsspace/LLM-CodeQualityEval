/**https://leetcode.com/problems/race-car/ */
//Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):
//	When you get an instruction 'A', your car does the following:
//	
//		position += speed
//		speed *= 2
//	
//	
//	When you get an instruction 'R', your car does the following:
//	
//		If your speed is positive then speed = -1
//		otherwise speed = 1
//	
//	Your position stays the same.
//For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.
//Given a target position target, return the length of the shortest sequence of instructions to get there.
// 
//Example 1:
//Input: target = 3
//Output: 2
//Explanation: 
//The shortest instruction sequence is "AA".
//Your position goes from 0 --> 1 --> 3.
//Example 2:
//Input: target = 6
//Output: 5
//Explanation: 
//The shortest instruction sequence is "AAARA".
//Your position goes from 0 --> 1 --> 3 --> 7 --> 7 --> 6.
// 
//Constraints:
//	1 <= target <= 104
/**
 * @param {number} target
 * @return {number}
 */
var racecar = function(target) {
    if (target === 1) return 1;
    let n = Math.floor(Math.log2(target));
    if (target === (1 << n) - 1) return n;
    let res = n + 1 + racecar((1 << n) - 1 - target);
    if (n > 1) {
        let m = Math.floor(Math.log2(target + (1 << (n - 1)) - (1 << n)));
        res = Math.min(res, n + 1 + m + racecar(target - (1 << m) + (1 << (n - 1))));
    }
    return res;
};
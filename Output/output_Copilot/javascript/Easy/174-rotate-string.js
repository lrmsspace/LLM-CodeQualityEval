/**https://leetcode.com/problems/rotate-string/ */
//Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
//A shift on s consists of moving the leftmost character of s to the rightmost position.
//	For example, if s = "abcde", then it will be "bcdea" after one shift.
// 
//Example 1:
//Input: s = "abcde", goal = "cdeab"
//Output: true
//Example 2:
//Input: s = "abcde", goal = "abced"
//Output: false
// 
//Constraints:
//	1 <= s.length, goal.length <= 100
//	s and goal consist of lowercase English letters.
/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function(s, goal) {
    if (s.length !== goal.length) return false; // Check if lengths are equal
    const doubleS = s + s; // Concatenate s with itself
    return doubleS.includes(goal); // Check if goal is a substring of doubleS    
};
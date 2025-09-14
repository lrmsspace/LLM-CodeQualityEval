/**https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/ */
//You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
//Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
// 
//Example 1:
//Input: s1 = "bank", s2 = "kanb"
//Output: true
//Explanation: For example, swap the first character with the last character of s2 to make "bank".
//Example 2:
//Input: s1 = "attack", s2 = "defend"
//Output: false
//Explanation: It is impossible to make them equal with one string swap.
//Example 3:
//Input: s1 = "kelb", s2 = "kelb"
//Output: true
//Explanation: The two strings are already equal, so no string swap operation is required.
// 
//Constraints:
//	1 <= s1.length, s2.length <= 100
//	s1.length == s2.length
//	s1 and s2 consist of only lowercase English letters.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var areAlmostEqual = function(s1, s2) {
    // Initialize a counter to track the number of different characters
    let diffCount = 0;
    // Initialize two pointers to iterate through the strings
    let i = 0;
    let j = 0;
    
    // Iterate through the strings simultaneously
    while (i < s1.length && j < s2.length) {
        // If the characters at the current indices are different, increment the counter
        if (s1[i]!== s2[j]) {
            diffCount++;
        }
        // Move to the next indices
        i++;
        j++;
    }
    
    // If the counter is greater than 1, it means we can't make the strings equal with a single swap
    return diffCount <= 1;
    
};
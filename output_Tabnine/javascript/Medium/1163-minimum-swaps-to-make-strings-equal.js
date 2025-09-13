/**https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/ */
//You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].
//Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.
// 
//Example 1:
//Input: s1 = "xx", s2 = "yy"
//Output: 1
//Explanation: Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
//Example 2:
//Input: s1 = "xy", s2 = "yx"
//Output: 2
//Explanation: Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
//Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
//Note that you cannot swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
//Example 3:
//Input: s1 = "xx", s2 = "xy"
//Output: -1
// 
//Constraints:
//	1 <= s1.length, s2.length <= 1000
//	s1.length == s2.length
//	s1, s2 only contain 'x' or 'y'.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
var minimumSwap = function(s1, s2) {
    let countX = 0, countY = 0;
    let swapCount = 0;
    
    // Count the number of 'x' and 'y' in both strings
    for (let i = 0; i < s1.length; i++) {
        if (s1[i] === 'x') countX++;
        else countY++;
    }
    
    // If the number of 'x' and 'y' is not equal, it's impossible to make both strings equal
    if (countX!== countY) return -1;
    
    // Iterate through the strings and swap the characters that belong to different strings
    for (let i = 0; i < s1.length; i++) {
        if (s1[i]!== s2[i]) {
            // Find the first character of the other string that needs to be swapped with s1[i]
            for (let j = 0; j < s1.length; j++) {
                if (s2[j] === s1[i] && s2[j]!== s2[i]) {
                    // Swap s1[i] and s2[j]
                    [s1[i], s2[j]] = [s2[j], s1[i]];
                    swapCount++;
                    break;
                }
            }
        }
    }
    
    return swapCount;
    
};
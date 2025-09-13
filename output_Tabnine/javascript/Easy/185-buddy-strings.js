/**https://leetcode.com/problems/buddy-strings/ */
//Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
//Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
//	For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
// 
//Example 1:
//Input: s = "ab", goal = "ba"
//Output: true
//Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
//Example 2:
//Input: s = "ab", goal = "ab"
//Output: false
//Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
//Example 3:
//Input: s = "aa", goal = "aa"
//Output: true
//Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
// 
//Constraints:
//	1 <= s.length, goal.length <= 2 * 104
//	s and goal consist of lowercase letters.
/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var buddyStrings = function(s, goal) {
    // If the strings have different lengths, they cannot be swapped to match
    if (s.length!== goal.length) return false;
    
    // Count the number of occurrences of each character in both strings
    let count = new Array(26).fill(0);
    for (let i = 0; i < s.length; i++) {
        count[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
        count[goal.charCodeAt(i) - 'a'.charCodeAt(0)]--;
    }
    
    // Check if there is a character with a non-zero count
    let hasNonZeroCount = false;
    for (let i = 0; i < count.length; i++) {
        if (count[i]!== 0) {
            if (hasNonZeroCount) return false;
            hasNonZeroCount = true;
        }
    }
    
    // Check if there are any two adjacent characters that are the same
    for (let i = 0; i < s.length - 1; i++) {
        if (s[i] === goal[i]) {
            if (s[i + 1]!== goal[i + 1]) return true;
        }
    }
    
    // If none of the conditions are met, return false
    return false;
    
};
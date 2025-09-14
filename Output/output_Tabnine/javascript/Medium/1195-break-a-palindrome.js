/**https://leetcode.com/problems/break-a-palindrome/ */
//Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.
//Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.
//A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, a has a character strictly smaller than the corresponding character in b. For example, "abcc" is lexicographically smaller than "abcd" because the first position they differ is at the fourth character, and 'c' is smaller than 'd'.
// 
//Example 1:
//Input: palindrome = "abccba"
//Output: "aaccba"
//Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
//Of all the ways, "aaccba" is the lexicographically smallest.
//Example 2:
//Input: palindrome = "a"
//Output: ""
//Explanation: There is no way to replace a single character to make "a" not a palindrome, so return an empty string.
// 
//Constraints:
//	1 <= palindrome.length <= 1000
//	palindrome consists of only lowercase English letters.
/**
 * @param {string} palindrome
 * @return {string}
 */
var breakPalindrome = function(palindrome) {
    if (palindrome.length === 1) return '';
    
    const n = palindrome.length;
    let result = palindrome;
    
    for (let i = 0; i < n - 1; i++) {
        if (palindrome[i]!== 'a') {
            result = result.slice(0, i) + 'a' + result.slice(i + 1);
            return result;
        }
    }
    
    return result.slice(0, -1) + 'b'; // If no character can be replaced to make it not a palindrome, return the last character as 'b' to make it lexicographically smallest.
    
};
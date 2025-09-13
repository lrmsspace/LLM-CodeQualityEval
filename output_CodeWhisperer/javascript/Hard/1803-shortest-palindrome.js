/**https://leetcode.com/problems/shortest-palindrome/ */
//You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//Return the shortest palindrome you can find by performing this transformation.
// 
//Example 1:
//Input: s = "aacecaaa"
//Output: "aaacecaaa"
//Example 2:
//Input: s = "abcd"
//Output: "dcbabcd"
// 
//Constraints:
//	0 <= s.length <= 5 * 104
//	s consists of lowercase English letters only.
/**
 * @param {string} s
 * @return {string}
 */
var shortestPalindrome = function(s) {
    let rev_s = s.split('').reverse().join('');
    for (let i = 0; i < s.length; i++) {
        if (s.substring(0, s.length - i) === rev_s.substring(i)) return rev_s.substring(0, i) + s;
    }
    return '';
};
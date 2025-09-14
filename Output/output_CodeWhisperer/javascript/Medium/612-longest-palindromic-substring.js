/**https://leetcode.com/problems/longest-palindromic-substring/ */
//Given a string s, return the longest palindromic substring in s.
// 
//Example 1:
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
//Example 2:
//Input: s = "cbbd"
//Output: "bb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consist of only digits and English letters.
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    
    let longest = "";
    for (let i = 0; i < s.length; i++) {
        let odd = expandAroundCenter(s, i, i);
        let even = expandAroundCenter(s, i, i + 1);
        let longer = odd.length > even.length ? odd : even;
        longest = longer.length > longest.length ? longer : longest;
    }
    return longest;

};
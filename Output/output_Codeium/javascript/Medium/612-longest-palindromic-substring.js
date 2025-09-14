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
    let longest = '';
    for (let i = 0; i < s.length; i++) {
        let oddLength = expandFromCenter(s, i, i);
        let evenLength = expandFromCenter(s, i, i + 1);
        let curLongest = oddLength.length > evenLength.length ? oddLength : evenLength;
        if (curLongest.length > longest.length) {
            longest = curLongest;
        }
    }
    return longest;
    
    function expandFromCenter(s, left, right) {
        while (left >= 0 && right < s.length && s[left] === s[right]) {
            left--;
            right++;
        }
        return s.slice(left + 1, right);
};
/**https://leetcode.com/problems/last-substring-in-lexicographical-order/ */
//Given a string s, return the last substring of s in lexicographical order.
// 
//Example 1:
//Input: s = "abab"
//Output: "bab"
//Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
//Example 2:
//Input: s = "leetcode"
//Output: "tcode"
// 
//Constraints:
//	1 <= s.length <= 4 * 105
//	s contains only lowercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var lastSubstring = function(s) {
    let maxChar = 'a', maxSubstr = '', i = s.length - 1;
    while (i >= 0) {
        if (s[i] > maxChar) {
            maxChar = s[i];
            maxSubstr = s.slice(i);
        } else if (s[i] === maxChar) {
            maxSubstr = s.slice(i);
        }
        i--;
    }
    return maxSubstr;    
};
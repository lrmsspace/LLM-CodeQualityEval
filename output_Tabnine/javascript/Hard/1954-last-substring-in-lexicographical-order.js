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
    let n = s.length;
    let max = '';
    
    for (let i = n - 1; i >= 0; i--) {
        let substring = s.slice(i);
        if (substring > max) {
            max = substring;
        }
    }
    
    return max;
    
};
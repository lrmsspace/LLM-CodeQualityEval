/**https://leetcode.com/problems/repeated-substring-pattern/ */
//Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
// 
//Example 1:
//Input: s = "abab"
//Output: true
//Explanation: It is the substring "ab" twice.
//Example 2:
//Input: s = "aba"
//Output: false
//Example 3:
//Input: s = "abcabcabcabc"
//Output: true
//Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {boolean}
 */
var repeatedSubstringPattern = function(s) {
    // Check if the string can be constructed by taking a substring of it and appending multiple copies of the substring together
    for (let i = 1; i <= s.length / 2; i++) {
        if (s.length % i === 0) {
            let substring = s.substr(0, i);
            let rest = s.substr(i);
            let isRepeat = true;
            while (rest.length > 0) {
                if (rest.indexOf(substring)!== 0) {
                    isRepeat = false;
                    break;
                }
                rest = rest.substr(substring.length);
            }
            if (isRepeat) {
                return true;
            }
        }
    }
    return false;
    
};
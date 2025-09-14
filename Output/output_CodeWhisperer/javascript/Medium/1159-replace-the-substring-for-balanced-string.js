/**https://leetcode.com/problems/replace-the-substring-for-balanced-string/ */
//You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.
//A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.
//Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.
// 
//Example 1:
//Input: s = "QWER"
//Output: 0
//Explanation: s is already balanced.
//Example 2:
//Input: s = "QQWE"
//Output: 1
//Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
//Example 3:
//Input: s = "QQQW"
//Output: 2
//Explanation: We can replace the first "QQ" to "ER". 
// 
//Constraints:
//	n == s.length
//	4 <= n <= 105
//	n is a multiple of 4.
//	s contains only 'Q', 'W', 'E', and 'R'.
/**
 * @param {string} s
 * @return {number}
 */
var balancedString = function(s) {
    let count = {'Q': 0, 'W': 0, 'E': 0, 'R': 0};
    for (let i = 0; i < s.length; i++) {
        count[s[i]]++;
    }
    let n = s.length / 4;
    let left = 0;
    let minLen = s.length;
    for (let right = 0; right < s.length; right++) {
        count[s[right]]--;
        while (left < s.length && count['Q'] <= n && count['W'] <= n && count['E'] <= n && count['R'] <= n) {
            minLen = Math.min(minLen, right - left + 1);
            count[s[left]]++;
            left++;
        }
    }
    return minLen;
};
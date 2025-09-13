/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
// 
//Example 1:
//Input: s = "banana"
//Output: "ana"
//Example 2:
//Input: s = "abcd"
//Output: ""
// 
//Constraints:
//	2 <= s.length <= 3 * 104
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var longestDupSubstring = function(s) {
    let n = s.length;
    let left = 0, right = n - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        let substring = s.substring(0, mid);
        let found = false;
        for (let i = 0; i <= n - mid; i++) {
            if (s.substring(i, i + mid) === substring) {
                found = true;
                break;
            }
        }
        if (found) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return s.substring(0, left - 1);
};
/**https://leetcode.com/problems/distinct-echo-substrings/ */
//Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).
// 
//Example 1:
//Input: text = "abcabcabc"
//Output: 3
//Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
//Example 2:
//Input: text = "leetcodeleetcode"
//Output: 2
//Explanation: The 2 substrings are "ee" and "leetcodeleetcode".
// 
//Constraints:
//	1 <= text.length <= 2000
//	text has only lowercase English letters.
/**
 * @param {string} text
 * @return {number}
 */
var distinctEchoSubstrings = function(text) {
    let n = text.length;
    let ans = 0;
    let set = new Set();
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            let len = j - i + 1;
            if (len % 2 === 0) {
                let mid = len / 2;
                let left = text.substring(i, i + mid);
                let right = text.substring(i + mid, j + 1);
                if (left === right) {
                    set.add(left);
                    ans++;
                }
            }
        }
    }
    return ans;    
};
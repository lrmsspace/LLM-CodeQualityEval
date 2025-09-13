/**https://leetcode.com/problems/repeated-string-match/ */
//Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.
//Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".
// 
//Example 1:
//Input: a = "abcd", b = "cdabcdab"
//Output: 3
//Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
//Example 2:
//Input: a = "a", b = "aa"
//Output: 2
// 
//Constraints:
//	1 <= a.length, b.length <= 104
//	a and b consist of lowercase English letters.
/**
 * @param {string} a
 * @param {string} b
 * @return {number}
 */
var repeatedStringMatch = function(a, b) {
    let n = a.length;
    let m = b.length;
    
    let k = Math.floor(m / n) + 2;
    let s = new Array(k * n).fill(a);
    
    for (let i = 1; i < k; i++) {
        if (s[i * n - 1] === b[0]) {
            let j = 0;
            for (; j < m; j++) {
                if (s[i * n + j]!== b[j]) break;
            }
            if (j === m) return i;
        }
        s[i * n] = s[i * n - n];
    }
    
    return -1;
    
};
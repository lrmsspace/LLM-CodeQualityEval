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
    let n = s.length;
    let i = 0;
    for (let j = n - 1; j >= 0; j--) {
        if (s[j] === s[i]) {
            i++;
        }
    }
    if (i === n) {
        return s;
    }
    let suffix = s.slice(i);
    return suffix.split("").reverse().join("") + shortestPalindrome(s.slice(0, i)) + suffix;
};
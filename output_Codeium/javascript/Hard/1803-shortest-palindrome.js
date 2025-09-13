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
    let rev = s.split("").reverse().join("");
    let l = s + "#" + rev;
    let dp = new Array(n * 2 + 1).fill(0);
    let j = 0, ans = 0;
    for (let i = 1; i < l.length; i++) {
        while (j > 0 && l[i] !== l[j]) {
            j = dp[j - 1];
        }
        if (l[i] === l[j]) {
            j++;
        }
        dp[i] = j;
        ans = Math.max(ans, j);
    }
    let res = "";
    for (let i = n - 1; i >= ans; i--) {
        res += s[i];
    }
    return res + s;
};
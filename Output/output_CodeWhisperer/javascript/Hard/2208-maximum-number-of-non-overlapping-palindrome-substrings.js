/**https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/ */
//You are given a string s and a positive integer k.
//Select a set of non-overlapping substrings from the string s that satisfy the following conditions:
//	The length of each substring is at least k.
//	Each substring is a palindrome.
//Return the maximum number of substrings in an optimal selection.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "abaccdbbd", k = 3
//Output: 2
//Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
//It can be shown that we cannot find a selection with more than two valid substrings.
//Example 2:
//Input: s = "adbcda", k = 2
//Output: 0
//Explanation: There is no palindrome substring of length at least 2 in the string.
// 
//Constraints:
//	1 <= k <= s.length <= 2000
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxPalindromes = function(s, k) {
    let n = s.length;
    let dp = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));
    let res = 0;
    for (let i = 0; i < n; i++) {
        dp[i][i] = 1;
        for (let j = 0; j < i; j++) {
            dp[j][i] = dp[j + 1][i - 1] && s[j] == s[i] ? 1 : 0;
            if (dp[j][i] == 1 && i - j + 1 >= k) {
                dp[j][i] = 1;
                res++;
            }
        }
    }
    for (let i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1] && dp[i][i + 1] == 0) {
            dp[i][i + 1] = 1;
            res++;
        }
    }
    return res;
};
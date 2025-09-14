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
class Solution {
    public int maxPalindromes(String s, int k) {
        int n = s.length(), res = 0;
        boolean[][] dp = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s.charAt(i) == s.charAt(j) && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (i - j + 1 >= k) {
                        res++;
                        break;
                    }
                }
            }
        }
        int[] f = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            for (int j = 0; j < i; j++) {
                if (dp[j][i - 1]) {
                    f[i] = Math.max(f[i], f[j] + 1);
                }
            }
        }
        return f[n];      
    }
}
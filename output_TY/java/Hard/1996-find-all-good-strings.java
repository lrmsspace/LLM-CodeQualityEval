/**https://leetcode.com/problems/find-all-good-strings/ */
//Given the strings s1 and s2 of size n and the string evil, return the number of good strings.
//A good string has size n, it is alphabetically greater than or equal to s1, it is alphabetically smaller than or equal to s2, and it does not contain the string evil as a substring. Since the answer can be a huge number, return this modulo 109 + 7.
// 
//Example 1:
//Input: n = 2, s1 = "aa", s2 = "da", evil = "b"
//Output: 51 
//Explanation: There are 25 good strings starting with 'a': "aa","ac","ad",...,"az". Then there are 25 good strings starting with 'c': "ca","cc","cd",...,"cz" and finally there is one good string starting with 'd': "da". 
//Example 2:
//Input: n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
//Output: 0 
//Explanation: All strings greater than or equal to s1 and smaller than or equal to s2 start with the prefix "leet", therefore, there is not any good string.
//Example 3:
//Input: n = 2, s1 = "gx", s2 = "gz", evil = "x"
//Output: 2
// 
//Constraints:
//	s1.length == n
//	s2.length == n
//	s1 <= s2
//	1 <= n <= 500
//	1 <= evil.length <= 50
//	All strings consist of lowercase English letters.
class Solution {
    public int findGoodStrings(int n, String s1, String s2, String evil) {
        int[] dp = new int[n + 1];
        int[] dp2 = new int[n + 1];
        int[] evil_hash = new int[evil.length() + 1];
        int mod = 1000000007;
        int res = 0;
        for (int i = 0; i < evil.length(); i++) {
            evil_hash[i + 1] = (evil_hash[i] * 26 + (evil.charAt(i) - 'a')) % mod;
        }
        for (int i = 1; i <= n; i++) {
            dp[i] = 1;
            for (int j = 1; j <= i; j++) {
                dp2[j] = (dp2[j - 1] * 26 + (s1.charAt(j - 1) - 'a')) % mod;
                int hash = (dp2[j] - dp2[0] + mod) % mod;
                if (hash == evil_hash[1]) {
                    dp[i] = (dp[i] - dp[j - 1] + mod) % mod;
                }
            }
            if (i >= 2)
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        }  
        return dp[n];
    }
}
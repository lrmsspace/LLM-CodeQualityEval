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
// Implement a method to find all good strings within given constraints
int mod = 1000000007;
int[][][] dp;
char[] evilChars;

public int findGoodStrings(int n, String s1, String s2, String evil) {
    evilChars = evil.toCharArray();
    dp = new int[n + 1][2][2];
    for (int[][] grid : dp) for (int[] row : grid) Arrays.fill(row, -1);
    return dfs(0, true, true, s1.toCharArray(), s2.toCharArray(), 0);
}

private int dfs(int index, boolean isS1Prefix, boolean isS2Prefix, char[] s1, char[] s2, int evilMatch) {
    if (evilMatch == evilChars.length) return 0; // evil string found
    if (index == s1.length) return 1; // valid string found

    if (dp[index][isS1Prefix ? 1 : 0][isS2Prefix ? 1 : 0] != -1) {
        return dp[index][isS1Prefix ? 1 : 0][isS2Prefix ? 1 : 0];
    }

    char from = isS1Prefix ? s1[index] : 'a';
    char to = isS2Prefix ? s2[index] : 'z';
    int count = 0;

    for (char ch = from; ch <= to; ch++) {
        int nextEvilMatch = evilMatch;
        while (nextEvilMatch > 0 && evilChars[nextEvilMatch] != ch) {
            nextEvilMatch--;
        }
        if (ch == evilChars[nextEvilMatch]) {
            nextEvilMatch++;
        }
        count = (count + dfs(index + 1, isS1Prefix && (ch == s1[index]), isS2Prefix && (ch == s2[index]), s1, s2, nextEvilMatch)) % mod;
    }
    
    return dp[index][isS1Prefix ? 1 : 0][isS2Prefix ? 1 : 0] = count;
}

}
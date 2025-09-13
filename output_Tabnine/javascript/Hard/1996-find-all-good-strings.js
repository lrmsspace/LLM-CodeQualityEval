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
/**
 * @param {number} n
 * @param {string} s1
 * @param {string} s2
 * @param {string} evil
 * @return {number}
 */
var findGoodStrings = function(n, s1, s2, evil) {
    const MOD = 10 ** 9 + 7;
    const m = 26;
    const dp = Array(n + 1).fill(0).map(() => Array(m).fill(0));
    
    // Count the number of good strings starting with each character
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            if (s1[i] <= String.fromCharCode(97 + j) && String.fromCharCode(97 + j) <= s2[i]) {
                dp[i + 1][j]++;
            }
        }
    }
    
    // Subtract the number of good strings containing the evil substring
    let evilIndex = -1;
    for (let i = 0; i < evil.length; i++) {
        evilIndex = s1.indexOf(evil[i], evilIndex + 1);
        if (evilIndex === -1) {
            break;
        }
        for (let j = 0; j < m; j++) {
            dp[evilIndex + 1][j] = (dp[evilIndex + 1][j] - dp[evilIndex][j]) % MOD;
        }
    }
    
    // Return the number of good strings
    let result = 0;
    for (let i = 0; i < m; i++) {
        result = (result + dp[n][i]) % MOD;
    }
    return result;
    
};
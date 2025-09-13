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
    let dp = new Array(n + 1).fill(0).map(() => new Array(evil.length + 1).fill(0).map(() => new Array(2).fill(0).map(() => new Array(2).fill(0))));
    let mod = 1000000007;
    let l = evil.length;

    let dfs = (i, ei, low, high) => {
        if (ei == l) return 0;
        if (i == n) return 1;
        if (dp[i][ei][low][high] != -1) return dp[i][ei][low][high];
        let res = 0;
        let start = low ? s1.charCodeAt(i) : 97;
        let end = high ? s2.charCodeAt(i) : 122;
        for (let c = start; c <= end; c++) {
            let nlow = low && c == s1.charCodeAt(i);
            let nhigh = high && c == s2.charCodeAt(i);
            let ne = ei;
            if (c == evil.charCodeAt(ei)) {
                if (ei == l - 1) continue;
                ne++;
            }
            res = (res + dfs(i + 1, ne, nlow, nhigh)) % mod;
        }
        dp[i][ei][low][high] = res;
        return res;
    }
    return dfs(0, 0, true, true);
};
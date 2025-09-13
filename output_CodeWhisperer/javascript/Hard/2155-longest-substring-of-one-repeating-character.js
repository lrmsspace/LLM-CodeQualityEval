/**https://leetcode.com/problems/longest-substring-of-one-repeating-character/ */
//You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.
//The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].
//Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.
// 
//Example 1:
//Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
//Output: [3,3,4]
//Explanation: 
//- 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
//- 2nd query updates s = "bbbccc". 
//  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
//- 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
//Thus, we return [3,3,4].
//Example 2:
//Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
//Output: [2,3]
//Explanation:
//- 1st query updates s = "abazz". The longest substring consisting of one repeating character is "zz" with length 2.
//- 2nd query updates s = "aaazz". The longest substring consisting of one repeating character is "aaa" with length 3.
//Thus, we return [2,3].
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters.
//	k == queryCharacters.length == queryIndices.length
//	1 <= k <= 105
//	queryCharacters consists of lowercase English letters.
//	0 <= queryIndices[i] < s.length
/**
 * @param {string} s
 * @param {string} queryCharacters
 * @param {number[]} queryIndices
 * @return {number[]}
 */
var longestRepeating = function(s, queryCharacters, queryIndices) {
    let n = s.length;
    let dp = new Array(n).fill(0).map(() => new Array(26).fill(0));
    let res = new Array(queryCharacters.length).fill(0);
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < 26; j++) {
            dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (s.charCodeAt(i) - 'a'.charCodeAt(0) == j ? 1 : 0);
        }
    }
    for (let i = 0; i < queryCharacters.length; i++) {
        let c = queryCharacters.charCodeAt(i) - 'a'.charCodeAt(0);
        for (let j = 0; j < 26; j++) {
            dp[queryIndices[i]][j] -= (c == j ? 1 : 0);
        }
        dp[queryIndices[i]][c] += 1;
        let max = 0;
        for (let j = 0; j < 26; j++) {
            max = Math.max(max, dp[queryIndices[i]][j]);
        }
        if (queryIndices[i] > 0) {
            max = Math.max(max, dp[queryIndices[i] - 1][c]);
        }
        if (queryIndices[i] < n - 1) {
            max = Math.max(max, dp[queryIndices[i] + 1][c]);
        }
        res[i] = max;
    }
    return res;
};
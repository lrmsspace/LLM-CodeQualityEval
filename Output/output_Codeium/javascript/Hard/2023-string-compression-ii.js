/**https://leetcode.com/problems/string-compression-ii/ */
//Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".
//Notice that in this problem, we are not adding '1' after single characters.
//Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.
//Find the minimum length of the run-length encoded version of s after deleting at most k characters.
// 
//Example 1:
//Input: s = "aaabcccd", k = 2
//Output: 4
//Explanation: Compressing s without deleting anything will give us "a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' would at most decrease the length of the compressed string to 5, for instance delete 2 'a' then we will have s = "abcccd" which compressed is abc3d. Therefore, the optimal way is to delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.
//Example 2:
//Input: s = "aabbaa", k = 2
//Output: 2
//Explanation: If we delete both 'b' characters, the resulting compressed string would be "a4" of length 2.
//Example 3:
//Input: s = "aaaaaaaaaaa", k = 0
//Output: 3
//Explanation: Since k is zero, we cannot delete anything. The compressed string is "a11" of length 3.
// 
//Constraints:
//	1 <= s.length <= 100
//	0 <= k <= s.length
//	s contains only lowercase English letters.
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLengthOfOptimalCompression = function(s, k) {
    let dp = new Array(s.length + 1).fill(0).map(() => new Array(k + 1).fill(Infinity));
    dp[0][0] = 0;
    for (let i = 1; i <= s.length; i++) {
        for (let j = 0; j <= k; j++) {
            if (j > 0) dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1] + 1);
            let count = 1;
            for (let l = i - 2; l >= 0; l--) {
                if (s[l] === s[i - 1]) count++;
                else break;
            }
            if (count > 1) dp[i][j] = Math.min(dp[i][j], dp[i - count][j] + (count < 10 ? 1 : count < 100 ? 2 : 3));
            dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + (i > 1 && s[i - 2] === s[i - 1] ? 0 : 1));
        }
    }
    return dp[s.length][k];
};
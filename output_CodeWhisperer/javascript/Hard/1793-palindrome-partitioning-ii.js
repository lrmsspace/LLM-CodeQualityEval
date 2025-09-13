/**https://leetcode.com/problems/palindrome-partitioning-ii/ */
//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return the minimum cuts needed for a palindrome partitioning of s.
// 
//Example 1:
//Input: s = "aab"
//Output: 1
//Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//Example 2:
//Input: s = "a"
//Output: 0
//Example 3:
//Input: s = "ab"
//Output: 1
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase English letters only.
/**
 * @param {string} s
 * @return {number}
 */
var minCut = function(s) {
    let n = s.length;
    let dp = new Array(n).fill(0).map(() => new Array(n).fill(false));
    let cut = new Array(n).fill(0);
    for (let j = 0; j < n; j++) {
        cut[j] = j;
        for (let i = 0; i <= j; i++) {
            if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                cut[j] = i == 0 ? 0 : Math.min(cut[j], cut[i - 1] + 1);
            }
        }
    }
    return cut[n - 1];
};
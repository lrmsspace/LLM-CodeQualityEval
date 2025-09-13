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
    const n = s.length;
    const dp = new Array(n).fill(0);
    const isPalindrome = new Array(n).fill(0).map(() => new Array(n).fill(false));

    for (let i = 0; i < n; i++) {
        dp[i] = i; // Maximum cuts
        for (let j = 0; j <= i; j++) {
            if ((s[i] === s[j]) && (i - j < 2 || isPalindrome[j + 1][i - 1])) {
                isPalindrome[j][i] = true;
                dp[i] = j === 0 ? 0 : Math.min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    return dp[n - 1];    
};
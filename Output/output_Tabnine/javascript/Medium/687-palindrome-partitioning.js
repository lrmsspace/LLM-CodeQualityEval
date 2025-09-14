/**https://leetcode.com/problems/palindrome-partitioning/ */
//Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// 
//Example 1:
//Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]
//Example 2:
//Input: s = "a"
//Output: [["a"]]
// 
//Constraints:
//	1 <= s.length <= 16
//	s contains only lowercase English letters.
/**
 * @param {string} s
 * @return {string[][]}
 */
var partition = function(s) {
    const dp = Array(s.length + 1).fill(null).map(() => Array(s.length + 1).fill(false));
    const palindrome = Array(s.length + 1).fill(null).map(() => Array(s.length + 1).fill(true));
    
    for (let i = 1; i <= s.length; i++) {
        for (let j = 1; j <= s.length - i + 1; j++) {
            if (s[j - 1] === s[j - 1 + i - 1] && palindrome[j][j + i - 1]) {
                palindrome[j][j + i - 1] = true;
                dp[j][j + i - 1] = true;
            }
        }
    }
    
    const result = [];
    function backtrack(start, path) {
        if (start === s.length) {
            result.push(path.slice());
            return;
        }
        
        for (let i = start; i < s.length; i++) {
            if (dp[start][i]) {
                backtrack(i + 1, [...path, s.slice(start, i + 1)]);
            }
        }
    }
    
    backtrack(0, []);
    return result;
    
};
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
    const res = [];
    const dfs = (s, tmp) => {
        if (!s) {
            res.push(tmp);
            return;
        }
        for (let i = 1; i <= s.length; i++) {
            const sub = s.substring(0, i);
            if (sub === sub.split('').reverse().join('')) {
                dfs(s.substring(i), tmp.concat([sub]));
            }
        }
    };
    dfs(s, []);
    return res;
    
};
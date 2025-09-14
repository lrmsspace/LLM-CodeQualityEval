/**https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/ */
//Given a string s, return the maximum number of unique substrings that the given string can be split into.
//You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "ababccc"
//Output: 5
//Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
//Example 2:
//Input: s = "aba"
//Output: 2
//Explanation: One way to split maximally is ['a', 'ba'].
//Example 3:
//Input: s = "aa"
//Output: 1
//Explanation: It is impossible to split the string any further.
// 
//Constraints:
//	
//	1 <= s.length <= 16
//	
//	
//	s contains only lower case English letters.
//	
/**
 * @param {string} s
 * @return {number}
 */
var maxUniqueSplit = function(s) {
    let n = s.length;
    let dp = Array(n+1).fill(0);
    let count = Array(26).fill(0);
    let res = 0;
    
    for(let i = 1; i <= n; i++) {
        count[s.charCodeAt(i-1) - 'a'.charCodeAt(0)]++;
        
        if(count[s.charCodeAt(i-1) - 'a'.charCodeAt(0)] === 1) {
            dp[i] = dp[i-1] + 1;
            res = Math.max(res, dp[i]);
        } else {
            dp[i] = dp[i-1];
        }
    }
    
    return res;
    
};
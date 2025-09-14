/*
 Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
 You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
 Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
 Since the answer may be very large, return it modulo 109 + 7.
 Example 1:
 Input: word = "aabbccdd", k = 7
 Output: 5
 Explanation:
 The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".
 Example 2:
 Input: word = "aabbccdd", k = 8
 Output: 1
 Explanation:
 The only possible string is "aabbccdd".
 Example 3:
 Input: word = "aaabbb", k = 3
 Output: 8
 Constraints:
 1 <= word.length <= 5 * 105
 word consists only of lowercase English letters.
 1 <= k <= 2000
*/

/**
 * @param {string} word
 * @param {number} k
 * @return {number}
 */
var possibleStringCount = function(word, k) {
    let n = word.length;
    let dp = new Array(n).fill().map(() => new Array(k+1).fill(-1));
    
    function solve(i, k) {
        if (k < 0) return 0;
        if (i < 0) return 1;
        if (dp[i][k] != -1) return dp[i][k];
        
        let ans = solve(i-1, k);
        ans += solve(i-1, k-1);
        
        return dp[i][k] = ans;
    }
    
    return solve(n-1, k);
    
};
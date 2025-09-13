/**https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/ */
//You are given a list of strings of the same length words and a string target.
//Your task is to form target using the given words under the following rules:
//	target should be formed from left to right.
//	To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
//	Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
//	Repeat the process until you form the string target.
//Notice that you can use multiple characters from the same string in words provided the conditions above are met.
//Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: words = ["acca","bbbb","caca"], target = "aba"
//Output: 6
//Explanation: There are 6 ways to form target.
//"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
//"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
//"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
//"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
//"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
//"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
//Example 2:
//Input: words = ["abba","baab"], target = "bab"
//Output: 4
//Explanation: There are 4 ways to form target.
//"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
//"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
//"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
//"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length <= 1000
//	All strings in words have the same length.
//	1 <= target.length <= 1000
//	words[i] and target contain only lowercase English letters.
/**
 * @param {string[]} words
 * @param {string} target
 * @return {number}
 */ 
var numWays = function(words, target) {
    const MOD = 1e9 + 7;
    const m = target.length;
    const n = words[0].length;
    
    // Create count array to store frequency of characters at each position
    const count = Array(n).fill().map(() => Array(26).fill(0));
    
    // Count frequency of characters at each position in words
    for (let i = 0; i < words.length; i++) {
        for (let j = 0; j < n; j++) {
            count[j][words[i].charCodeAt(j) - 97]++;
        }
    }
    
    // dp[i][j] represents number of ways to form target[0...i] using first j columns
    const dp = Array(m + 1).fill().map(() => Array(n + 1).fill(0));
    dp[0][0] = 1;
    
    // Fill dp table
    for (let i = 0; i <= m; i++) {
        for (let j = 0; j < n; j++) {
            if (i < m) {
                // Current character in target
                const curr = target.charCodeAt(i) - 97;
                // Add number of ways using current column
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + 
                    (dp[i][j] * count[j][curr]) % MOD) % MOD;
            }
            // Add number of ways without using current column
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
        }
    }
    
    return dp[m][n];
};

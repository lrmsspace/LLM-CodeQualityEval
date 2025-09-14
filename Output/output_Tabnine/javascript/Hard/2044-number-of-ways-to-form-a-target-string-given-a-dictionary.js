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
    const len = target.length;
    const dp = Array.from({ length: len + 1 }, () => Array(26).fill(0));
    dp[0][0] = 1;
    const freq = Array.from({ length: 26 }, () => 0);
    
    for (let i = 0; i < len; i++) {
        const prev = dp.slice(0, i + 1);
        dp.fill(Array(26).fill(0));
        
        for (let j = 0; j < 26; j++) {
            if (prev[i][j] > 0) {
                for (let k = 0; k < words.length; k++) {
                    const idx = words[k].indexOf(target[i]);
                    if (idx >= 0 && idx <= freq[j]) {
                        dp[i + 1][(j + words[k].charCodeAt(idx) - 'a'.charCodeAt(0)) % 26] = (dp[i + 1][(j + words[k].charCodeAt(idx) - 'a'.charCodeAt(0)) % 26] + prev[i][j]) % MOD;
                    }
                }
            }
            freq[j]++;
        }
    }
    
    return dp[len][0];
    
};
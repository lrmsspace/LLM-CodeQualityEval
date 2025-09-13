/*
 You are given an array of strings words. Find all shortest common supersequences (SCS) of words that are not permutations of each other.
 A shortest common supersequence is a string of minimum length that contains each string in words as a subsequence.
 Return a 2D array of integers freqs that represent all the SCSs. Each freqs[i] is an array of size 26, representing the frequency of each letter in the lowercase English alphabet for a single SCS. You may return the frequency arrays in any order.
 Example 1:
 Input: words = ["ab","ba"]
 Output: [[1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],[2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
 Explanation:
 The two SCSs are "aba" and "bab". The output is the letter frequencies for each one.
 Example 2:
 Input: words = ["aa","ac"]
 Output: [[2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
 Explanation:
 The two SCSs are "aac" and "aca". Since they are permutations of each other, keep only "aac".
 Example 3:
 Input: words = ["aa","bb","cc"]
 Output: [[2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
 Explanation:
 "aabbcc" and all its permutations are SCSs.
 Constraints:
 1 <= words.length <= 256
 words[i].length == 2
 All strings in words will altogether be composed of no more than 16 unique lowercase letters.
 All strings in words are unique.
*/

/**
 * @param {string[]} words
 * @return {number[][]}
 */
var supersequences = function(words) {
    let n = words.length;
    let dp = Array.from(Array(n), () => Array(1 << n).fill(0));
    for (let i = 0; i < n; i++) {
        dp[i][1 << i] = words[i].length;
    }
    for (let mask = 0; mask < (1 << n); mask++) {
        for (let i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;
            for (let j = 0; j < n; j++) {
                if ((mask & (1 << j)) > 0) continue;
                dp[j][mask | (1 << j)] = Math.max(dp[j][mask | (1 << j)], dp[i][mask] + words[j].length);
            }
        }
    }
    let ans = [0, 0];
    for (let i = 0; i < n; i++) {
        ans[0] = Math.max(ans[0], dp[i][(1 << n) - 1]);
        ans[1] = Math.max(ans[1], dp[i][(1 << n) - 1] - words[i].length);
    }
    return ans[0] <= 0 ? -1 : ans[1];
    
};
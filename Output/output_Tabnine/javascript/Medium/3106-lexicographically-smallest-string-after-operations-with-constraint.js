/*
 You are given a string s and an integer k.
 Define a function distance(s1, s2) between two strings s1 and s2 of the same length n as:
 The sum of the minimum distance between s1[i] and s2[i] when the characters from 'a' to 'z' are placed in a cyclic order, for all i in the range [0, n - 1].
 For example, distance("ab", "cd") == 4, and distance("a", "z") == 1.
 You can change any letter of s to any other lowercase English letter, any number of times.
 Return a string denoting the lexicographically smallest string t you can get after some changes, such that distance(s, t) <= k.
 Example 1:
 Input: s = "zbbz", k = 3
 Output: "aaaz"
 Explanation:
 Change s to "aaaz". The distance between "zbbz" and "aaaz" is equal to k = 3.
 Example 2:
 Input: s = "xaxcd", k = 4
 Output: "aawcd"
 Explanation:
 The distance between "xaxcd" and "aawcd" is equal to k = 4.
 Example 3:
 Input: s = "lol", k = 0
 Output: "lol"
 Explanation:
 It's impossible to change any character as k = 0.
 Constraints:
 1 <= s.length <= 100
 0 <= k <= 2000
 s consists only of lowercase English letters.
*/

/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var getSmallestString = function(s, k) {
    let n = s.length;       
    let dp = Array(n + 1).fill(Number.MAX_SAFE_INTEGER);
    dp[0] = 0;
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j < 26; j++) {
            let prevChar = (s[i - 1].charCodeAt(0) - 'a'.charCodeAt(0) + j) % 26 + 'a'.charCodeAt(0);
            dp[i] = Math.min(dp[i], dp[i - 1] + prevChar.charCodeAt(0) - s[i - 1].charCodeAt(0));
        }
    }
    let ans = '';
    for (let i = n; i >= 1; i--) {
        let minDist = Number.MAX_SAFE_INTEGER;
        for (let j = 0; j < 26; j++) {
            let prevChar = (s[i - 1].charCodeAt(0) - 'a'.charCodeAt(0) + j) % 26 + 'a'.charCodeAt(0);
            if (dp[i - 1] + prevChar.charCodeAt(0) - s[i - 1].charCodeAt(0) === minDist) {
                ans = String.fromCharCode(prevChar) + ans;
                minDist = dp[i - 1] + prevChar.charCodeAt(0) - s[i - 1].charCodeAt(0);
                break;
            }
        }
    }   
    return ans; 
    
};
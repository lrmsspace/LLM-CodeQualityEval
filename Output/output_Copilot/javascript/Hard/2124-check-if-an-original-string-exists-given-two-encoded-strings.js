/**https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/ */
//An original string, consisting of lowercase English letters, can be encoded by the following steps:
//	Arbitrarily split it into a sequence of some number of non-empty substrings.
//	Arbitrarily choose some elements (possibly none) of the sequence, and replace each with its length (as a numeric string).
//	Concatenate the sequence as the encoded string.
//For example, one way to encode an original string "abcdefghijklmnop" might be:
//	Split it as a sequence: ["ab", "cdefghijklmn", "o", "p"].
//	Choose the second and third elements to be replaced by their lengths, respectively. The sequence becomes ["ab", "12", "1", "p"].
//	Concatenate the elements of the sequence to get the encoded string: "ab121p".
//Given two encoded strings s1 and s2, consisting of lowercase English letters and digits 1-9 (inclusive), return true if there exists an original string that could be encoded as both s1 and s2. Otherwise, return false.
//Note: The test cases are generated such that the number of consecutive digits in s1 and s2 does not exceed 3.
// 
//Example 1:
//Input: s1 = "internationalization", s2 = "i18n"
//Output: true
//Explanation: It is possible that "internationalization" was the original string.
//- "internationalization" 
//  -> Split:       ["internationalization"]
//  -> Do not replace any element
//  -> Concatenate:  "internationalization", which is s1.
//- "internationalization"
//  -> Split:       ["i", "nternationalizatio", "n"]
//  -> Replace:     ["i", "18",                 "n"]
//  -> Concatenate:  "i18n", which is s2
//Example 2:
//Input: s1 = "l123e", s2 = "44"
//Output: true
//Explanation: It is possible that "leetcode" was the original string.
//- "leetcode" 
//  -> Split:      ["l", "e", "et", "cod", "e"]
//  -> Replace:    ["l", "1", "2",  "3",   "e"]
//  -> Concatenate: "l123e", which is s1.
//- "leetcode" 
//  -> Split:      ["leet", "code"]
//  -> Replace:    ["4",    "4"]
//  -> Concatenate: "44", which is s2.
//Example 3:
//Input: s1 = "a5b", s2 = "c5b"
//Output: false
//Explanation: It is impossible.
//- The original string encoded as s1 must start with the letter 'a'.
//- The original string encoded as s2 must start with the letter 'c'.
// 
//Constraints:
//	1 <= s1.length, s2.length <= 40
//	s1 and s2 consist of digits 1-9 (inclusive), and lowercase English letters only.
//	The number of consecutive digits in s1 and s2 does not exceed 3.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var possiblyEquals = function(s1, s2) {
    const dp = new Array(s1.length + 1).fill(0).map(() => new Array(s2.length + 1).fill(false));
    dp[0][0] = true;
    for (let i = 1; i <= s1.length; i++) {
        if (isNaN(s1[i - 1])) {
            dp[i][0] = dp[i - 1][0];
        } else {
            dp[i][0] = false;
        }
    }
    for (let j = 1; j <= s2.length; j++) {
        if (isNaN(s2[j - 1])) {
            dp[0][j] = dp[0][j - 1];
        } else {
            dp[0][j] = false;
        }
    }
    for (let i = 1; i <= s1.length; i++) {
        for (let j = 1; j <= s2.length; j++) {
            if (isNaN(s1[i - 1]) && isNaN(s2[j - 1])) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (!isNaN(s1[i - 1]) && !isNaN(s2[j - 1])) {
                const lenS1 = parseInt(s1[i - 1]);
                const lenS2 = parseInt(s2[j - 1]);
                for (let k = Math.max(0, lenS2 - lenS1); k <= Math.min(lenS2, lenS2 + lenS1); k++) {
                    if (dp[i - lenS2 + k][j - lenS2 + k]) {
                        dp[i][j] = true;
                        break;
                    }
                }
            } else if (!isNaN(s1[i - 1])) {
                const lenS2 = parseInt(s2[j - 1]);
                for (let k = Math.max(0, lenS2); k <= Math.min(lenS2 + parseInt(s1[i - 1]), s2.length); k++) {
                    if (dp[i - lenS2 + k][j]) {
                        dp[i][j] = true;
                        break;
                    }
                }
            } else {
                const lenS1 = parseInt(s1 [i - 1]);
                for (let k = Math.max(0, lenS1); k <= Math.min(lenS1 + parseInt(s2[j - 1]), s1.length); k++) {
                    if (dp[i][j - lenS1 + k]) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
    }
    return dp[s1.length][s2.length];   
};
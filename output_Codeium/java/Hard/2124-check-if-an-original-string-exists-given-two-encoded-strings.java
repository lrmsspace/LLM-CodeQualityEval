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
class Solution {
    public boolean possiblyEquals(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();
        boolean[][] dp = new boolean[n1 + 1][n2 + 1];
        dp[0][0] = true;
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i > 0 && Character.isLetter(s1.charAt(i - 1))) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (j > 0 && Character.isLetter(s2.charAt(j - 1))) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
                if (i > 0 && j > 0 && Character.isDigit(s1.charAt(i - 1)) && Character.isDigit(s2.charAt(j - 1))) {
                    int k = i - 1, cnt = 0;
                    while (k >= 0 && Character.isDigit(s1.charAt(k))) {
                        cnt = cnt * 10 + (s1.charAt(k--) - '0');
                    }
                    int l = j - 1, cnt2 = 0;
                    while (l >= 0 && Character.isDigit(s2.charAt(l))) {
                        cnt2 = cnt2 * 10 + (s2.charAt(l--) - '0');
                    }
                    if (cnt == cnt2) {
                        dp[i][j] = dp[i][j] || dp[k + 1][l + 1];
                    }
                }
            }
        }
        return dp[n1][n2];
    }
}
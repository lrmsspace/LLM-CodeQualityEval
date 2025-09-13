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
public:
    bool possiblyEquals(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<unordered_set<int>>> dp(n1 + 1, vector<unordered_set<int>>(n2 + 1));
        dp[n1][n2].insert(0);
        for (int i = n1 - 1; i >= 0; --i) {
            int j = n2;
            while (j >= 0) {
                for (int x : dp[i + 1][j]) {
                    if (x > 0 && s1[i] >= 'a' && s1[i] <= 'z') {
                        dp[i][j].insert(x - 1);
                    }
                }
                if (j < n2 && s2[j] >= 'a' && s2[j] <= 'z') {
                    for (int x : dp[i][j + 1]) {
                        if (x > 0) {
                            dp[i][j].insert(x + 1);
                        }
                    }
                }
                if (j < n2 && s2[j] >= '1' && s2[j] <= '9') {
                    int val = 0;
                    for (int k = j; k < n2 && s2[k] >= '0' && s2[k] <= '9'; ++k) {
                        val = val * 10 + (s2[k] - '0');
                        if (val > 100) {
                            break;
                        }
                        dp[i][j].insert(val);
                    }
                }
                if (j < n2 && s2[j] >= 'a' && s2[j] <= 'z') {
                    for (int x : dp[i][j + 1]) {
                        if (x <= 0) {
                            dp[i][j].insert(x);
                        }
                    }
                }
                --j;
            }
        }
        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j <= n2; ++j) {
                for (int x : dp[i][j]) {
                    if (x == 0) {
                        return true;
                    }
                }
            }
        }
        return false;     
    }
};
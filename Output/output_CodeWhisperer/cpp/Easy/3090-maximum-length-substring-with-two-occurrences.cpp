/*
 Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 Example 1:
 Input: s = "bcbbbcba"
 Output: 4
 Explanation:
 The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
 Example 2:
 Input: s = "aaaa"
 Output: 2
 Explanation:
 The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 Constraints:
 2 <= s.length <= 100
 s consists only of lowercase English letters.
*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxLen = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            int count[26] = {0};
            for (int j = i; j < len; j++) {
                count[s[j] - 'a']++;
                if (count[s[j] - 'a'] > 2) {
                    break;
                }
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
        
    }
};
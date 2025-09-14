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
        int n = s.length();
        int maxLen = 0;
        int count[26] = {0};
        
        for (int i = 0, j = 0; i < n; i++) {
            count[s[i] - 'a']++;
            while (count[s[i] - 'a'] > 2) {
                count[s[j] - 'a']--;
                j++;
            }
            maxLen = max(maxLen, i - j + 1);
        }
        
        return maxLen;
        
    }
};
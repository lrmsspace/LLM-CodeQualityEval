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
        int maxLength = 0;
        unordered_map<char, int> charCount;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            charCount[s[right]]++;

            while (charCount[s[right]] > 2) {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0) {
                    charCount.erase(s[left]);
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
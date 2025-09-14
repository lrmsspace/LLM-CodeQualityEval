/**https://leetcode.com/problems/longest-nice-substring/ */
//A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
//Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
// 
//Example 1:
//Input: s = "YazaAay"
//Output: "aAa"
//Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
//"aAa" is the longest nice substring.
//Example 2:
//Input: s = "Bb"
//Output: "Bb"
//Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
//Example 3:
//Input: s = "c"
//Output: ""
//Explanation: There are no nice substrings.
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of uppercase and lowercase English letters.
class Solution {
public:
    string longestNiceSubstring(string s) {
        unordered_map<char, int> charCount;
        int left = 0, right = 0;
        int maxLen = 0;
        while (right < s.size()) {
            charCount[tolower(s[right++])]++;
            while (right - left > 2 && charCount[tolower(s[left])] > 1) {
                charCount[tolower(s[left++])]--;
            }
            if (right - left > 2 && charCount[tolower(s[left])] == 1 && charCount[toupper(s[left])] == 1) {
                maxLen = max(maxLen, right - left);
            }
        }
        return maxLen == 0? "" : s.substr(left, maxLen);
        
    }
};
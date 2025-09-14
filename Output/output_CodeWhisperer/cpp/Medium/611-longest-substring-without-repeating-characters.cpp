/**https://leetcode.com/problems/longest-substring-without-repeating-characters/ */
//Given a string s, find the length of the longest substring without repeating characters.
// 
//Example 1:
//Input: s = "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
//Example 2:
//Input: s = "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
//Example 3:
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
// 
//Constraints:
//	0 <= s.length <= 5 * 104
//	s consists of English letters, digits, symbols and spaces.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int left = 0, right = 0;
        int maxLen = 0;
        unordered_set<char> charSet;
        while (right < n) {
            if (charSet.find(s[right]) == charSet.end()) {
                charSet.insert(s[right]);
                right++;
                maxLen = max(maxLen, right - left);
            } else {
                charSet.erase(s[left]);
                left++;
            }
        }
        return maxLen;       
    }
};
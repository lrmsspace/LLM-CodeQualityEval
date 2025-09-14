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
int lengthOfLongestSubstring(char* s) {
    int maxLength = 0;
    int start = 0;
    int charIndex[256] = {0}; // Initialize an array to store the index of characters

    for (int i = 0; s[i] != '\0'; i++) {
        if (charIndex[s[i]] > start) {
            start = charIndex[s[i]];
        }
        charIndex[s[i]] = i + 1; // Update the index of the character
        if (i - start + 1 > maxLength) {
            maxLength = i - start + 1;
        }
    }

    return maxLength;
}

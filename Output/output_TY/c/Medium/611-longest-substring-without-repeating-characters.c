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
int lengthOfLongestSubstring(char * s){
    int max_len = 0;
    int len = strlen(s);
    int i, j;
    for (i = 0; i < len; i++) {
        int hash[128] = {0};
        for (j = i; j < len; j++) {
            hash[s[j]]++;
            if (hash[s[j]] > 1) break;
        }
        max_len = max(max_len, j - i);
    }
    return max_len;
}
/**https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/ */
//Given a string s, return the maximum number of occurrences of any substring under the following rules:
//	The number of unique characters in the substring must be less than or equal to maxLetters.
//	The substring size must be between minSize and maxSize inclusive.
// 
//Example 1:
//Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
//Output: 2
//Explanation: Substring "aab" has 2 occurrences in the original string.
//It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
//Example 2:
//Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
//Output: 2
//Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
// 
//Constraints:
//	1 <= s.length <= 105
//	1 <= maxLetters <= 26
//	1 <= minSize <= maxSize <= min(26, s.length)
//	s consists of only lowercase English letters.
int maxFreq(char* s, int maxLetters, int minSize, int maxSize) {
    int n = strlen(s);
    int count[26] = {0};
    int unique = 0;
    int max = 0;
    int left = 0;
    int right = 0;
    int freq[26][n + 1] = {0};
    while (right < n) {
        if (count[s[right] - 'a'] == 0) {
            unique++;
        }
        count[s[right] - 'a']++;
        right++;
        while (unique > maxLetters || right - left > maxSize) {
            if (count[s[left] - 'a'] == 1) {
                unique--;
            }
            count[s[left] - 'a']--;
            left++;
        }
        if (right - left >= minSize) {
            freq[s[left] - 'a'][right - left]++;
            if (freq[s[left] - 'a'][right - left] > max) {
                max = freq[s[left] - 'a'][right - left];
            }
        }
    }
    return max;
}
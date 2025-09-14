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
    int max_freq = 0;
    int window_start = 0;
    int char_freq[26] = {0};

    for (int window_end = 0; window_end < strlen(s); window_end++) {
        char_freq[s[window_end] - 'a']++;
        while (window_end - window_start + 1 > minSize && char_freq[s[window_start] - 'a'] > 0) {
            char_freq[s[window_start] - 'a']--;
            window_start++;
        }
        if (window_end - window_start + 1 >= minSize && window_end - window_start + 1 <= maxSize) {
            max_freq = fmax(max_freq, window_end - window_start + 1);
        }
    }

    return max_freq;
}
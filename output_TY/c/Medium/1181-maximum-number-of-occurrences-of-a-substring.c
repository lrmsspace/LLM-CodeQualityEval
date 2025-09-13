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
int maxFreq(char * s, int maxLetters, int minSize, int maxSize){
    int i, j, k, l, cnt, ans = 0;
    int freq[26] = {0}, freq2[26] = {0};
    for (i = 0; i < minSize; i++) freq[s[i] - 'a']++;
    for (i = minSize; i <= maxSize; i++) {
        cnt = 0;
        for (j = 0; j < 26; j++) freq2[j] = freq[j];
        for (j = 0; j < i; j++) freq2[s[j] - 'a']--;
    }
    for (i = minSize; i <= maxSize; i++) {
        for (j = 0; j <= 26; j++) freq[j] = 0;
        for (j = 0; j < i; j++) freq[s[j] - 'a']++;
        for (j = i, k = 0; j <= strlen(s); j++, k++) {
            if (k < i) freq[s[j] - 'a']++;
        }
    }
    for (i = 0; i < 26; i++) ans += freq[i] / minSize;
    return ans;
}
/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
char* reorganizeString(char* s) {
    int count[26] = {0}, maxCount = 0, maxCharIndex = -1;
    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
        if (count[s[i] - 'a'] > maxCount) {
            maxCount = count[s[i] - 'a'];
            maxCharIndex = i;
        }
    }
    if (maxCount > (s.length + 1) / 2) return "";
    char* result = malloc((s.length + 1) * sizeof(char));
    int i = 0;
    for (i = 0; i < maxCount; i++) {
        result[i * 2] = s[maxCharIndex];
        count[s[maxCharIndex] - 'a']--;
        if (count[s[maxCharIndex] - 'a'] == 0) {
            for (int j = maxCharIndex + 1; s[j] && count[s[j] - 'a'] > 0; j++) {
                result[i * 2 + 1] = s[j];
                count[s[j] - 'a']--;
                s[j] = s[maxCharIndex + 1];
                maxCharIndex = j;
            }
        }
    }
    for (i = maxCount; i < s.length; i++) {
        result[i * 2] = s[i];
    }
    result[s.length] = '\0';
    return result;
}
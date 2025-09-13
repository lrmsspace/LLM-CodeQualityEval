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

int maximumLengthSubstring(char* s) {
    int max = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int count[26] = {0};
        int j = i;
        while (j < len) {
            if (count[s[j] - 'a'] == 2) {
                break;
            }
            count[s[j] - 'a']++;
            j++;
        }
        if (j - i > max) {
            max = j - i;
        }
    }
    return max;    
}
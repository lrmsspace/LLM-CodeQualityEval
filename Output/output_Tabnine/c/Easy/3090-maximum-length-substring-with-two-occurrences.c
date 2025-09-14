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
    int charCount[26] = {0};
    int maxLength = 0;
    int start = 0;
    
    for (int end = 0; end < strlen(s); end++) {
        charCount[s[end] - 'a']++;
        
        while (charCount[s[end] - 'a'] > 2) {
            charCount[s[start] - 'a']--;
            start++;
        }
        
        maxLength = fmax(maxLength, end - start + 1);
    }
    
    return maxLength;
    
}
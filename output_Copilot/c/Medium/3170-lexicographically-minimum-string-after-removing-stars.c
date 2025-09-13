/*
 You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
 While there is a '*', do the following operation:
 Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
 Return the lexicographically smallest resulting string after removing all '*' characters.
 Example 1:
 Input: s = "aaba*"
 Output: "aab"
 Explanation:
 We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.
 Example 2:
 Input: s = "abc"
 Output: "abc"
 Explanation:
 There is no '*' in the string.
 Constraints:
 1 <= s.length <= 105
 s consists only of lowercase English letters and '*'.
 The input is generated such that it is possible to delete all '*' characters.
*/

char* clearStars(char* s) {
    int n = 0, i = 0, j = 0;
    char* result = (char*)malloc(strlen(s) + 1);
    
    // Count non-star characters
    while (s[n]) {
        if (s[n] != '*') {
            n++;
        }
        n++;
    }
    
    // Process the string
    while (s[i]) {
        if (s[i] == '*') {
            // Find the smallest character to remove
            int minIndex = -1;
            for (int k = j - 1; k >= 0; k--) {
                if (result[k] < s[i]) {
                    minIndex = k;
                    break;
                }
            }
            if (minIndex != -1) {
                // Remove the character at minIndex
                for (int k = minIndex; k < j - 1; k++) {
                    result[k] = result[k + 1];
                }
                j--;
            }
        } else {
            result[j++] = s[i];
        }
        i++;
    }
    
    result[j] = '\0';
    return result;    
}
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
    int count[26] = {0};
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        count[s[i] - 'a']++;
    }
    
    int maxCount = 0, maxChar = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxChar = i;
        }
    }
    
    if (maxCount > (length + 1) / 2) {
        return "";
    }
    
    char* result = (char*)malloc((length + 1) * sizeof(char));
    result[length] = '\0';
    
    int index = 0;
    while (count[maxChar] > 0) {
        result[index] = 'a' + maxChar;
        index += 2;
        count[maxChar]--;
    }
    
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            if (index >= length) {
                index = 1;
            }
            result[index] = 'a' + i;
            index += 2;
            count[i]--;
        }
    }
    
    return result;
}
    
    
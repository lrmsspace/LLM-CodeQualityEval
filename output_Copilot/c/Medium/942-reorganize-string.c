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
    int len = strlen(s);
    int *count = (int*)malloc(sizeof(int)*26);
    memset(count, 0, sizeof(int)*26);
    for (int i = 0; i < len; i++) {
        count[s[i]-'a']++;
    }
    int max = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > count[max]) {
            max = i;
        }
    }
    if (count[max] > (len+1)/2) {
        return "";
    }
    char *res = (char*)malloc(sizeof(char)*(len+1));
    int index = 0;
    while (count[max] > 0) {
        res[index] = 'a' + max;
        index += 2;
        count[max]--;
    }
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            if (index >= len) {
                index = 1;
            }
            res[index] = 'a' + i;
            index += 2;
            count[i]--;
        }
    }
    res[len] = '\0';
    return res;    
}
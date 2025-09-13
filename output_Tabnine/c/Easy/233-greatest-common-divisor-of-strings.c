/**https://leetcode.com/problems/greatest-common-divisor-of-strings/ */
//For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
//Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
// 
//Example 1:
//Input: str1 = "ABCABC", str2 = "ABC"
//Output: "ABC"
//Example 2:
//Input: str1 = "ABABAB", str2 = "ABAB"
//Output: "AB"
//Example 3:
//Input: str1 = "LEET", str2 = "CODE"
//Output: ""
// 
//Constraints:
//	1 <= str1.length, str2.length <= 1000
//	str1 and str2 consist of English uppercase letters.
char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 == 0 || len2 == 0) return "";
    int i, j, k = 0;
    while (k < len1 && k < len2 && str1[k] == str2[k]) k++;
    if (k == 0) return "";
    char* result = (char*)malloc((k + 1) * sizeof(char));
    result[k] = '\0';
    for (i = k; i > 0; i--) {
        for (j = 0; j + i <= k; j += i) {
            if (strncmp(str1 + j, str2, i) == 0 && strncmp(str1, str2 + j, i) == 0) {
                strncpy(result, str2, i);
                break;
            }
        }
        if (j + i <= k) break;
    }
    return result;
}
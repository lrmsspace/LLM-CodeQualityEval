/**https://leetcode.com/problems/greatest-common-divisor-of-strings/ */
//For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).
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
char * gcdOfStrings(char * str1, char * str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j;
    int maxLen = 0;
    int maxIndex = 0;
    for (i = 1; i <= len1; i++) {
        if (len1 % i == 0) {
            for (j = 0; j < len2; j++) {
                if (str2[j]!= str1[j % i]) {
                    break;
                }
            }
        }
    }
    if (j == len2) {
        maxLen = i;
        maxIndex = j;
    }
    char * result = (char *)malloc(maxLen + 1);
    for (i = 0; i < maxLen; i++) {
        result[i] = str1[i + maxIndex];
    }
    result[maxLen] = '\0';
    return result;
}
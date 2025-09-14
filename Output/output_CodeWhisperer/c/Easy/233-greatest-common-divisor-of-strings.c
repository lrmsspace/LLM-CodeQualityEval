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
    int len1 = strlen(str1), len2 = strlen(str2);
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (str1[i] == str2[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    if (i == len1) {
        return str1;
    } else {
        return gcdOfStrings(str2, str1 + i);
    }
    
}
/**https://leetcode.com/problems/reverse-words-in-a-string/ */
//Given an input string s, reverse the order of the words.
//A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
//Return a string of the words in reverse order concatenated by a single space.
//Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
// 
//Example 1:
//Input: s = "the sky is blue"
//Output: "blue is sky the"
//Example 2:
//Input: s = "  hello world  "
//Output: "world hello"
//Explanation: Your reversed string should not contain leading or trailing spaces.
//Example 3:
//Input: s = "a good   example"
//Output: "example good a"
//Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
// 
//Constraints:
//	1 <= s.length <= 104
//	s contains English letters (upper-case and lower-case), digits, and spaces ' '.
//	There is at least one word in s.
// 
//Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
char * reverseWords(char * s){
    int i, j, k, l, m, n, p;
    int len = strlen(s);
    char *res = (char *)malloc(sizeof(char) * len);
    int res_len = 0;
    for (i = 0; i < len; i++) {
        if (s[i] == ' ') continue;
        for (j = i; j < len; j++) {
            if (s[j] == ' ') break;
        }
    }
    for (i = j - 1; i >= 0; i--) {
        if (s[i] == ' ') continue;
        for (j = i; j >= 0; j--) {
            if (s[j] == ' ') break;
        }
        for (k = j + 1; k <= i; k++) {
            res[res_len++] = s[k];
        }
        res[res_len++] = ' ';
    }
    res[res_len - 1] = '\0';
    return res;
}
/**https://leetcode.com/problems/reverse-words-in-a-string-iii/ */
//Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
// 
//Example 1:
//Input: s = "Let's take LeetCode contest"
//Output: "s'teL ekat edoCteeL tsetnoc"
//Example 2:
//Input: s = "God Ding"
//Output: "doG gniD"
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	s contains printable ASCII characters.
//	s does not contain any leading or trailing spaces.
//	There is at least one word in s.
//	All the words in s are separated by a single space.
char * reverseWords(char * s){
    int i, j, k, len = strlen(s);
    char *p = s;
    for (i = 0; i < len; i++) {
        if (s[i] == ' ') {
            for (j = i - 1, k = i + 1; j > -1 && k < len; j--, k++) {
                char tmp = s[j];
                s[j] = s[k];
            }
        }
    }
    for (j = len - 1; j > -1; j--) {
        if (s[j] == ' ') {
            for (i = j - 1, k = j + 1; i > -1 && k < len; i--, k++) {
                char tmp = s[i];
                s[i] = s[k];
            }
        }
    }
    return p;
}
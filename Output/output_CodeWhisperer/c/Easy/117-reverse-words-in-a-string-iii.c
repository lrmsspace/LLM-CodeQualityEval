/**https://leetcode.com/problems/reverse-words-in-a-string-iii/ */
//Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
// 
//Example 1:
//Input: s = "Let's take LeetCode contest"
//Output: "s'teL ekat edoCteeL tsetnoc"
//Example 2:
//Input: s = "Mr Ding"
//Output: "rM gniD"
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	s contains printable ASCII characters.
//	s does not contain any leading or trailing spaces.
//	There is at least one word in s.
//	All the words in s are separated by a single space.
char* reverseWords(char* s) {
    int i, j, k;
    for (i = 0; i < strlen(s); i = j + 1) {
        for (j = i; j < strlen(s) && s[j] != ' '; j++);
        for (k = 0; k < (j - i) / 2; k++) {
            char tmp = s[i + k];
            s[i + k] = s[j - 1 - k];
            s[j - 1 - k] = tmp;
        }
    }
    return s;
    
}
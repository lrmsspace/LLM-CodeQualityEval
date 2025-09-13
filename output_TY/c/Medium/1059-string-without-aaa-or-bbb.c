/**https://leetcode.com/problems/string-without-aaa-or-bbb/ */
//Given two integers a and b, return any string s such that:
//	s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
//	The substring 'aaa' does not occur in s, and
//	The substring 'bbb' does not occur in s.
// 
//Example 1:
//Input: a = 1, b = 2
//Output: "abb"
//Explanation: "abb", "bab" and "bba" are all correct answers.
//Example 2:
//Input: a = 4, b = 1
//Output: "aabaa"
// 
//Constraints:
//	0 <= a, b <= 100
//	It is guaranteed such an s exists for the given a and b.


char * strWithout3a3b(int a, int b){
    char *s = malloc(sizeof(char) * (a + b + 1));
    int i = 0;
    while (a > 0 && b > 0) {
        if (a < b) {
            s[i++] = 'b';
            s[i++] = 'a';
            b--;
            a--;
        } else {
            s[i++] = 'a';
            s[i++] = 'b';
        }
    }
    while (a--) s[i++] = 'a';
    while (b--) s[i++] = 'b';
    s[i] = '\0';
    return s;
}
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
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int len = a + b;
    char *ret = (char *)malloc(sizeof(char) * (len + 1));
    ret[len] = '\0';
    for(i = 0; i < len; i++) {
        if(a > b) {
            if(i < len - 2 && i % 2 == 0) {
                ret[i] = 'a';
                a--;
            } else {
                ret[i] = 'b';
                b--;
            }
        } else {
            if(i < len - 2 && i % 2 == 0) {
                ret[i] = 'b';
                b--;
            } else {
                ret[i] = 'a';
                a--;
            }
        }
    }
    return ret;
}
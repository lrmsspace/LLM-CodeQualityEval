/**https://leetcode.com/problems/decode-string/ */
//Given an encoded string, return its decoded string.
//The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
//The test cases are generated so that the length of the output will never exceed 105.
// 
//Example 1:
//Input: s = "3[a]2[bc]"
//Output: "aaabcbc"
//Example 2:
//Input: s = "3[a2[c]]"
//Output: "accaccacc"
//Example 3:
//Input: s = "2[abc]3[cd]ef"
//Output: "abcabccdcdcdef"
// 
//Constraints:
//	1 <= s.length <= 30
//	s consists of lowercase English letters, digits, and square brackets '[]'.
//	s is guaranteed to be a valid input.
//	All the integers in s are in the range [1, 300].
char * decodeString(char * s){
    int i, j, k, n, m, t, a, b, c, d, e, f, g, h, l, r, p, q, x, y, z, w, v, u, o, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q, q
    char *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9, *s10, *s11, *s12, *s13, *s14, *s15, *s16, *s17, *s18, *s19, *s20, *s21, *s22, *s23, *s24, *s25, *s26, *s27, *s28, *s29, *s30
    for (i = 0; s[i]; i++) {
        if (s[i] == '[') {
            s1 = s + i + 1;
            for (j = i; s[j]; j++) {
                if (s[j] == ']') {
                    s2 = s + j;
                    break;
                }
            }
            s3 = s + i - 1;
            for (k = 0; s3[k]; k++) {
                if (isdigit(s3[k])) {
                    n = atoi(s3 + k);
                    break;
                }
            }
        }
    }
    return s2;
}
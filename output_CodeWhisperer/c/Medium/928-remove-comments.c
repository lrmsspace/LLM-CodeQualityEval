/**https://leetcode.com/problems/remove-comments/ */
//Given a C++ program, remove comments from it. The program source is an array of strings source where source[i] is the ith line of the source code. This represents the result of splitting the original source code string by the newline character '\n'.
//In C++, there are two types of comments, line comments, and block comments.
//	The string "//" denotes a line comment, which represents that it and the rest of the characters to the right of it in the same line should be ignored.
//	The string "/*" denotes a block comment, which represents that all characters until the next (non-overlapping) occurrence of "*/" should be ignored. (Here, occurrences happen in reading order: line by line from left to right.) To be clear, the string "/*/" does not yet end the block comment, as the ending would be overlapping the beginning.
//The first effective comment takes precedence over others.
//	For example, if the string "//" occurs in a block comment, it is ignored.
//	Similarly, if the string "/*" occurs in a line or block comment, it is also ignored.
//If a certain line of code is empty after removing comments, you must not output that line: each string in the answer list will be non-empty.
//There will be no control characters, single quote, or double quote characters.
//	For example, source = "string s = "/* Not a comment. */";" will not be a test case.
//Also, nothing else such as defines or macros will interfere with the comments.
//It is guaranteed that every open block comment will eventually be closed, so "/*" outside of a line or block comment always starts a new comment.
//Finally, implicit newline characters can be deleted by block comments. Please see the examples below for details.
//After removing the comments from the source code, return the source code in the same format.
// 
//Example 1:
//Input: source = ["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]
//Output: ["int main()","{ ","  ","int a, b, c;","a = b + c;","}"]
//Explanation: The line by line code is visualized as below:
///*Test program */
//int main()
//{ 
//  // variable declaration 
//int a, b, c;
///* This is a test
//   multiline  
//   comment for 
//   testing */
//a = b + c;
//}
//The string /* denotes a block comment, including line 1 and lines 6-9. The string // denotes line 4 as comments.
//The line by line output code is visualized as below:
//int main()
//{ 
//  
//int a, b, c;
//a = b + c;
//}
//Example 2:
//Input: source = ["a/*comment", "line", "more_comment*/b"]
//Output: ["ab"]
//Explanation: The original source string is "a/*comment\nline\nmore_comment*/b", where we have bolded the newline characters.  After deletion, the implicit newline characters are deleted, leaving the string "ab", which when delimited by newline characters becomes ["ab"].
// 
//Constraints:
//	1 <= source.length <= 100
//	0 <= source[i].length <= 80
//	source[i] consists of printable ASCII characters.
//	Every open block comment is eventually closed.
//	There are no single-quote or double-quote in the input.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** removeComments(char** source, int sourceSize, int* returnSize) {
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, ii = 0, jj = 0, kk = 0, ll = 0, mm = 0, nn = 0, oo = 0, pp = 0, qq = 0, rr = 0, ss = 0, tt = 0, uu = 0, vv = 0, ww = 0, xx = 0, yy = 0, zz = 0;
    int* arr = (int*)malloc(sizeof(int) * sourceSize);
    char** result = (char**)malloc(sizeof(char*) * sourceSize);
    for (i = 0; i < sourceSize; i++) {
        arr[i] = 0;
        result[i] = (char*)malloc(sizeof(char) * 100);
        for (j = 0; j < 100; j++) {
            result[i][j] = '\0';
        }
    }

    for (i = 0; i < sourceSize; i++) {
        for (j = 0; j < strlen(source[i]); j++) {
            if (source[i][j] == '/' && source[i][j + 1] == '*') {
                arr[i] = 1;
                j++;
            }
            else if (source[i][j] == '/' && source[i][j + 1] == '/') {
                arr[i] = 2;
                break;
            }
            else if (arr[i] == 1 && source[i][j] == '*' && source[i][j + 1] == '/') {
                arr[i] = 0;
                j++;
            }
            else if (arr[i] == 0) {
                result[k][l++] = source[i][j];
            }
        }
        if (l > 0 && arr[i] == 0) {
            k++;
            l = 0;
        }
    }
    *returnSize = k;
    return result;
}
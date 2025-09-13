/**https://leetcode.com/problems/count-binary-substrings/ */
//Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
//Substrings that occur multiple times are counted the number of times they occur.
// 
//Example 1:
//Input: s = "00110011"
//Output: 6
//Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
//Notice that some of these substrings repeat and are counted the number of times they occur.
//Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
//Example 2:
//Input: s = "10101"
//Output: 4
//Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is either '0' or '1'.
int countBinarySubstrings(char * s){
    int i, j, k, l, m, n, p, q, r, t, u, v, w, x, y, z;
    int a[100000], b[100000];
    int c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int count = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == '0') {
            a[i] = 1;
            b[i] = 0;
        }
        else {
            a[i] = 0;
            b[i] = 1;
        }
    }
    for (i = 0; i < strlen(s); i++) {
        if (a[i] == 1) {
            j = i;
            while (j < strlen(s) && a[j] == 1) {
                j++;
            }
            count += j - i;
            i = j - 1;
        }
    }
    for (i = 0; i < strlen(s); i++) {
        if (b[i] == 1) {
            j = i;
            while (j < strlen(s) && b[j] == 1) {
                j++;
            }
            count += j - i;
            i = j - 1;
        }
    }
    return count;
}
/**https://leetcode.com/problems/largest-palindromic-number/ */
//You are given a string num consisting of digits only.
//Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.
//Notes:
//	You do not need to use all the digits of num, but you must use at least one digit.
//	The digits can be reordered.
// 
//Example 1:
//Input: num = "444947137"
//Output: "7449447"
//Explanation: 
//Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
//It can be shown that "7449447" is the largest palindromic integer that can be formed.
//Example 2:
//Input: num = "00009"
//Output: "9"
//Explanation: 
//It can be shown that "9" is the largest palindromic integer that can be formed.
//Note that the integer returned should not contain leading zeroes.
// 
//Constraints:
//	1 <= num.length <= 105
//	num consists of digits.
char * largestPalindromic(char * num){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, ii, jj, kk, ll, mm, nn, oo, pp, qq, rr, ss, tt, uu, vv, ww, xx, yy, zz, aa, bb, cc, dd, ee, ff, gg, hh    ;
    int a1[10];
    memset(a1, 0, sizeof(a1));
    for (i = 0; i < strlen(num); i++) {
        a1[num[i] - '0']++;
    }
    for (i = 9; i >= 0; i--) {
        if (a1[i] % 2) {
            break;
        }
    }
    if (i == -1) {
        return "0";
    } else {
        char * res = (char *)malloc(sizeof(char) * 100);
        res[0] = '0' + i;
        res[1] = '\0';
        return res;
    }
    return "0";
}
/**https://leetcode.com/problems/thousand-separator/ */
//Given an integer n, add a dot (".") as the thousands separator and return it in string format.
// 
//Example 1:
//Input: n = 987
//Output: "987"
//Example 2:
//Input: n = 1234
//Output: "1.234"
// 
//Constraints:
//	0 <= n <= 231 - 1
char* thousandSeparator(int n) {
    char *res = (char *)malloc(12);
    char *p = res;
    if (n == 0) {
        *p++ = '0';
        *p = '\0';
        return res;
    }
    int count = 0;
    while (n) {
        *p++ = n % 10 + '0';
        n /= 10;
        count++;
        if (count % 3 == 0 && n) {
            *p++ = '.';
        }
    }
    *p = '\0';
    char *q = res;
    p--;
    while (q < p) {
        char t = *q;
        *q = *p;
        *p = t;
        q++;
        p--;
    }
    return res;    
}
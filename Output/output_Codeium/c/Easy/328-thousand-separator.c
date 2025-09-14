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
    char str[20];
    int len = sprintf(str, "%d", n);
    int k = 0;
    for (int i = len - 1; i > 0; i--) {
        k++;
        if (k % 3 == 0 && i != len - 1) {
            str[i] = '.';
            k = 0;
        }
    }
    return strdup(str);
}
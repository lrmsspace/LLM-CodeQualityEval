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
char * thousandSeparator(int n){
    char *s = malloc(sizeof(char) * 100);
    int i = 0;
    int j = 0;
    while (n > 0) {
        s[i++] = n % 10 + '0';
        n /= 10;
        j++;
        if (j % 3 == 0 && n > 0) {
            s[i++] = '.';
        }
    }
    s[i] = '\0';
    int k = 0;
    for (int j = i - 1; j >= 0; j--) {
        s[k++] = s[j];
    }
    s[k] = '\0';
    return s;
}
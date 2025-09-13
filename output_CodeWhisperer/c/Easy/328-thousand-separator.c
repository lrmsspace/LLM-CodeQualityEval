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
    if (n == 0) {
        char* res = (char*)malloc(2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    char* res = (char*)malloc(20);
    int i = 0;
    while (n > 0) {
        if (i > 0 && i % 3 == 0) {
            res[i++] = '.';
        }
        res[i++] = n % 10 + '0';
        n /= 10;
    }
    res[i] = '\0';
    int j = 0;
    while (j < i / 2) {
        char temp = res[j];
        res[j] = res[i - j - 1];
        res[i - j - 1] = temp;
        j++;
    }
    return res;
    
}
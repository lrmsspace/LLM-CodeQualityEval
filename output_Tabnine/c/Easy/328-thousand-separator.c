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
    char* result = malloc(sizeof(char) * (n + 1));
    int count = 0;
    int i = n;
    while (i > 0) {
        result[count++] = '0' + i % 10;
        i /= 10;
        if (count % 3 == 0 && i > 0) {
            result[count++] = '.';
        }
    }
    result[count] = '\0';
    char* reversed = malloc(sizeof(char) * (count + 1));
    int j = 0;
    for (int i = count - 1; i >= 0; i--) {
        reversed[j++] = result[i];
    }
    free(result);
    return reversed;
}
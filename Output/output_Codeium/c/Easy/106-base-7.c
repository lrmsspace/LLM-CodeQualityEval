/**https://leetcode.com/problems/base-7/ */
//Given an integer num, return a string of its base 7 representation.
// 
//Example 1:
//Input: num = 100
//Output: "202"
//Example 2:
//Input: num = -7
//Output: "-10"
// 
//Constraints:
//	-107 <= num <= 107
char* convertToBase7(int num) {
    if (num == 0) return "0";
    char *res = (char *)malloc(32 * sizeof(char));
    int i = 0;
    int sign = (num < 0) ? -1 : 1;
    num *= sign;
    while (num) {
        res[i++] = (num % 7) + '0';
        num /= 7;
    }
    if (sign == -1) res[i++] = '-';
    res[i] = '\0';
    reverse(res, res + i);
    return res;
    
}
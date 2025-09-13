/**https://leetcode.com/problems/fraction-to-recurring-decimal/ */
//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//If the fractional part is repeating, enclose the repeating part in parentheses.
//If multiple answers are possible, return any of them.
//It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
// 
//Example 1:
//Input: numerator = 1, denominator = 2
//Output: "0.5"
//Example 2:
//Input: numerator = 2, denominator = 1
//Output: "2"
//Example 3:
//Input: numerator = 4, denominator = 333
//Output: "0.(012)"
// 
//Constraints:
//	-231 <= numerator, denominator <= 231 - 1
//	denominator != 0
char* fractionToDecimal(int numerator, int denominator) {
    char* result = (char*)malloc(sizeof(char) * 1000);
    int i = 0;
    long long n = numerator;
    long long d = denominator;
    long long r = n % d;
    long long q = n / d;
    if (r == 0) {
        sprintf(result, "%lld", q);
        return result;
    }
    if (n * d < 0) {
        sprintf(result, "-%lld.", q);
    } else {
        sprintf(result, "%lld.", q);
    }
    i = strlen(result);
    n = r * 10;
    int* map = (int*)malloc(sizeof(int) * 1000);
    memset(map, -1, sizeof(int) * 1000);
    while (n != 0) {
        if (map[n] != -1) {
            result[map[n]] = '(';
            result[i] = ')';
            result[i + 1] = '\0';
            return result;
        }
        map[n] = i;
        q = n / d;
        r = n % d;
        result[i] = q + '0';
        result[i + 1] = '\0';
        n = r * 10;
        i++;
    }
    return result;
}
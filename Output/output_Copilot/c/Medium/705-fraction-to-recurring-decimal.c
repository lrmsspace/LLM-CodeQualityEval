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
    if (numerator == 0) return "0";
    char *res = (char *)malloc(20 * sizeof(char));
    if ((numerator > 0) ^ (denominator > 0)) strcat(res, "-");
    long long num = abs((long long)numerator);
    long long den = abs((long long)denominator);
    sprintf(res + strlen(res), "%lld", num / den);
    num %= den;
    if (num == 0) return res;
    strcat(res, ".");
    char *p = res + strlen(res);
    long long rem = num;
    int index = 0;
    bool flag = false;
    while (rem) {
        rem *= 10;
        if (flag) {
            if (rem == num) {
                p[index++] = '(';
                break;
            }
        }
        p[index++] = rem / den + '0';
        rem %= den;
        if (rem == num) {
            p[index++] = ')';
            break;
        }
        if (index == 1 && p[0] == '0') {
            flag = true;
            p[index++] = '.';
        }
    }
    p[index] = '\0';
    return res;    
}
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
    if (denominator == 0) return "";
    int sign = (numerator > 0) ^ (denominator > 0) ? -1 : 1;
    long long n = labs(numerator), d = labs(denominator);
    long long int_part = n / d;
    long long remainder = n % d;
    char* res = (char*)malloc(sizeof(char) * 100);
    if (sign == -1) res[0] = '-';
    sprintf(res + (sign == -1), "%lld", int_part);
    if (remainder == 0) return res;

    int idx = strlen(res);
    res[idx++] = '.';
    unordered_map<long long, int> m;
    while (remainder != 0) {
        if (m.find(remainder) != m.end()) {
            int start = m[remainder];
            char* temp = (char*)malloc(sizeof(char) * (idx - start + 3));
            strncpy(temp, res + start, idx - start);
            temp[idx - start] = ')';
            temp[idx - start + 1] = '\0';
            res[start] = '(';
            strcat(res, temp);
            free(temp);
            break;
        }
        m[remainder] = idx;
        remainder *= 10;
        res[idx++] = (remainder / d) + '0';
        remainder %= d;
    }
    return res;
}

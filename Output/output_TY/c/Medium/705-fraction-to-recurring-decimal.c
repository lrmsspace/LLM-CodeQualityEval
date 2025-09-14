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
char * fractionToDecimal(int numerator, int denominator){
    char *res = (char *)malloc(sizeof(char) * 1000);
    memset(res, 0, sizeof(char) * 1000);
    int i = 0;
    int flag = 0;
    if (numerator == 0) {
        res[i++] = '0';
        res[i] = '\0';
        return res;
    }
    if (numerator < 0){
        flag = 1;
    }
    numerator = abs(numerator);
    if (denominator < 0){
        flag = !flag;
    }
    denominator = abs(denominator);
    if (flag){
        res[i++] = '-';
    }
    long long num = numerator;
    long long den = denominator;
    long long div = num / den;
    long long mod = num % den;
    sprintf(res + i, "%lld", div);
    i += strlen(res + i);
    if (mod == 0){
        res[i] = '\0';
        return res;
    }
    res[i++] = '.';
    int j= i;
    while (mod){
        mod *= 10;
        div = mod / den;
        sprintf(res + i, "%lld", div);
        i += strlen(res + i);
        mod = mod % den;
    }
    for (int k = j; k < i; k++){
        for (int l = i - 1; l > k; l--){
            if (res[k] == res[l]){
                int len = l - k;
                int flag = 1;
                for (int m = 0; m < len; m++){
                    if (res[k + m] != res[l - m]){
                       flag = 0;
                    }
                }
            }
        }
    }
    return res;
}
/**https://leetcode.com/problems/integer-to-english-words/ */
//Convert a non-negative integer num to its English words representation.
// 
//Example 1:
//Input: num = 123
//Output: "One Hundred Twenty Three"
//Example 2:
//Input: num = 12345
//Output: "Twelve Thousand Three Hundred Forty Five"
//Example 3:
//Input: num = 1234567
//Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// 
//Constraints:
//	0 <= num <= 231 - 1


void helper(int num, char **res, int *len, const char *thousand) {
    if (num == 0) return;

    if (num < 20) {
        *len += sprintf(*res + *len, "%s", ones[num]);
    } else {
        *len += sprintf(*res + *len, "%s", tens[num / 10 - 1]);
        if (num % 10 != 0) {
            *len += sprintf(*res + *len, "-%s", ones[num % 10]);
        }
    }

    if (thousand) {
        *len += sprintf(*res + *len, " %s", thousand);
    }
}

char* numberToWords(int num) {
    if (num == 0) return "Zero";

    int i = 0;
    char *res = (char *)malloc(200 * sizeof(char));
    int len = 0;

    while (num > 0) {
        if (num % 1000 != 0) {
            helper(num % 1000, &res, &len, thousands[i]);
            if (i > 0) {
                len += sprintf(res + len, " ");
            }
        }
        num /= 1000;
        ++i;
    }

    return res;
}
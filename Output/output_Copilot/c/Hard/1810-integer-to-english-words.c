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
char* numberToWords(int num) {
    if (num == 0) return "Zero";
    char *result = (char *)malloc(1024);
    result[0] = '\0';
    char *str = (char *)malloc(1024);
    str[0] = '\0';
    int i = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            strcpy(str, "");
            helper(num % 1000, str);
            switch (i) {
                case 0:
                    break;
                case 1:
                    strcat(str, " Thousand");
                    break;
                case 2:
                    strcat(str, " Million");
                    break;
                case 3:
                    strcat(str, " Billion");
                    break;
            }
            strcat(str, " ");
            strcat(str, result);
            strcpy(result, str);
        }
        num /= 1000;
        i++;
    }
    free(str);
    return result;    
}
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
    if (num == 0) {
        char* result = (char*)malloc(sizeof(char) * 4);
        strcpy(result, "Zero");
        return result;
    }

    char* result = (char*)malloc(sizeof(char) * 100);

    char* ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char* tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char* thousands[] = {"", "Thousand", "Million", "Billion"};
    int thousandsIndex = 0;
    int hundreds = num % 1000;

    while (num > 0) {
        if (hundreds != 0) {
            char* hundredsStr = (char*)malloc(sizeof(char) * 100);
            int hundredsIndex = 0;

            if (hundreds >= 100) {
                strcat(hundredsStr, ones[hundreds / 100]);
                strcat(hundredsStr, " Hundred");
                hundredsIndex = strlen(hundredsStr);
            }

            int tensNum = hundreds % 100;
            if (tensNum >= 20) {
                if (hundredsIndex > 0) {
                    strcat(hundredsStr, " ");
                }
                strcat(hundredsStr, tens[tensNum / 10]);
                hundredsIndex = strlen(hundredsStr);
                if (tensNum % 10 != 0) {
                    if (hundredsIndex > 0) {
                        strcat(hundredsStr, " ");
                    }
                    strcat(hundredsStr, ones[tensNum % 10]);
                }
            } else if (tensNum != 0) {
                if (hundredsIndex > 0) {
                    strcat(hundredsStr, " ");
                }
                strcat(hundredsStr, ones[tensNum]);
            }

            if (thousandsIndex > 0) {
                char* thousandsStr = (char*)malloc(sizeof(char) * 100);
                strcpy(thousandsStr, thousands[thousandsIndex]);
                if (strlen(hundredsStr) > 0) {
                    strcat(thousandsStr, " ");
                    strcat(thousandsStr, hundredsStr);
                }
                strcat(thousandsStr, " ");
                strcat(thousandsStr, result);
                strcpy(result, thousandsStr);
            } else {
                if (strlen(hundredsStr) > 0) {
                    if (strlen(result) > 0) {
                        strcat(result, " ");
                    }
                    strcat(result, hundredsStr);
                }
            }
        }

        thousandsIndex++;
        num /= 1000;
        hundreds = num % 1000;
    }
    return result;  
    
}
/**https://leetcode.com/problems/largest-palindromic-number/ */
//You are given a string num consisting of digits only.
//Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.
//Notes:
//	You do not need to use all the digits of num, but you must use at least one digit.
//	The digits can be reordered.
// 
//Example 1:
//Input: num = "444947137"
//Output: "7449447"
//Explanation: 
//Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
//It can be shown that "7449447" is the largest palindromic integer that can be formed.
//Example 2:
//Input: num = "00009"
//Output: "9"
//Explanation: 
//It can be shown that "9" is the largest palindromic integer that can be formed.
//Note that the integer returned should not contain leading zeroes.
// 
//Constraints:
//	1 <= num.length <= 105
//	num consists of digits.
char* largestPalindromic(char* num) {
    int* count = (int*)calloc(10, sizeof(int));
    for (int i = 0; i < strlen(num); i++) {
        count[num[i] - '0']++;
    }
    int* result = (int*)calloc(strlen(num) + 1, sizeof(int));
    int resultIndex = 0;
    for (int i = 9; i >= 0; i--) {
        if (i == 0 && resultIndex == 0) {
            break;
        }
        while (count[i] > 1) {
            result[resultIndex++] = i;
            count[i] -= 2;
        }
    }
    if (resultIndex == 0) {
        result[resultIndex++] = 0;
    }
    for (int i = 9; i >= 0; i--) {
        if (count[i] > 0) {
            result[resultIndex] = i;
            break;
        }
    }
    char* resultString = (char*)calloc(resultIndex + 1, sizeof(char));
    for (int i = 0; i < resultIndex; i++) {
        resultString[i] = result[i] + '0';
    }
    free(count);
    free(result);
    return resultString;
}
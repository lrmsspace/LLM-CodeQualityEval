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
char * convertToBase7(int num){
    char * result = malloc(sizeof(char) * 32);
    int i = 0;
    int sign = 1;
    if (num < 0) {
        sign = -1;
        num = -num;
    }
    while (num) {
        result[i++] = num % 7 + '0';
        num /= 7;
    }
    if (i == 0) {
        result[i++] = '0';
    }
    if (sign == -1) {
        result[i++] = '-';
    }
    result[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }
    return result;
}
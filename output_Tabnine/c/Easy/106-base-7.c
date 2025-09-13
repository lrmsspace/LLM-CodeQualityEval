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

    // Handle negative numbers
    bool isNegative = num < 0;
    num = abs(num);
    
    // Initialize result string with empty space
    char* result = (char*)malloc(sizeof(char) * 33);
    result[32] = '\0';
    
    // Convert each digit to base 7 and store in result string
    int index = 31;
    while (num > 0) {
        int digit = num % 7;
        result[index--] = '0' + digit;
        num /= 7;
    }
    
    // Add '-' sign if num is negative
    if (isNegative) {
        result[--index] = '-';
    }
    
    return &result[index];
    
}
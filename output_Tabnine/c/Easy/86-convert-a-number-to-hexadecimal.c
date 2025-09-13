/**https://leetcode.com/problems/convert-a-number-to-hexadecimal/ */
//Given a 32-bit integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.
//All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.
//Note: You are not allowed to use any built-in library method to directly solve this problem.
// 
//Example 1:
//Input: num = 26
//Output: "1a"
//Example 2:
//Input: num = -1
//Output: "ffffffff"
// 
//Constraints:
//	-231 <= num <= 231 - 1
char* toHex(int num) {
    static const char* hex = "0123456789abcdef";
    if (num == 0) {
        return "0";
    }
    char* result = (char*)malloc(9 * sizeof(char));
    int i = 8;
    bool isNegative = num < 0;
    if (isNegative) {
        num = -num;
    }
    while (num > 0) {
        result[i--] = hex[num & 15];
        num >>= 4;
    }
    if (isNegative) {
        result[0] = '-';
    }
    return result;
}
/**https://leetcode.com/problems/convert-a-number-to-hexadecimal/ */
//Given an integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.
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
char * toHex(int num){
    char *hex = "0123456789abcdef";
    char *res = (char *)malloc(sizeof(char) * 16);
    int i = 0;
    unsigned int n = num;
    if (n == 0) {
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    while (n != 0) {
        res[i++] =hex[n % 16];
    }
    res[i] = '\0';
    reverse(res, i);
    return res;
}
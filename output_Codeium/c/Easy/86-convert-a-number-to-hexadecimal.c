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
    if (num == 0) return "0";
    char *res = (char *)malloc(9 * sizeof(char));
    int i = 0;
    for (; num && i < 8; ++i) {
        int t = num & 0xf;
        if (t < 10) res[i] = t + '0';
        else res[i] = t - 10 + 'a';
        num >>= 4;
    }
    res[i] = '\0';
    return res;
}
/**https://leetcode.com/problems/convert-to-base-2/ */
//Given an integer n, return a binary string representing its representation in base -2.
//Note that the returned string should not have leading zeros unless the string is "0".
// 
//Example 1:
//Input: n = 2
//Output: "110"
//Explantion: (-2)2 + (-2)1 = 2
//Example 2:
//Input: n = 3
//Output: "111"
//Explantion: (-2)2 + (-2)1 + (-2)0 = 3
//Example 3:
//Input: n = 4
//Output: "100"
//Explantion: (-2)2 = 4
// 
//Constraints:
//	0 <= n <= 109
char* baseNeg2(int n) {
    // Your code here
    char* result = (char*)malloc(sizeof(char) * 32); // Maximum 31 bits for base -2
    int index = 31;
    result[index--] = '\0';
    
    while (n!= 0) {
        int remainder = n & 1;
        n >>= 1;
        if (remainder == 1) {
            n--;
        }
        if (n < 0) {
            remainder = -remainder;
        }
        if (remainder >= 2) {
            result[index--] = '1';
        } else {
            result[index--] = '0';
        }
    }
    
    if (result[0] == '\0') {
        result = realloc(result, sizeof(char) * 2);
        result[0] = '0';
        result[1] = '\0';
    }
    
    return result;
    
}
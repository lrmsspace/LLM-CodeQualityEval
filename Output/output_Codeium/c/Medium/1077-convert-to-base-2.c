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
    if (n == 0) {
        char* result = (char*)malloc(2);
        strcpy(result, "0");
        return result;
    }

    char* result = (char*)malloc(40); // Allocate enough space for the result
    int index = 0;

    while (n != 0) {
        int remainder = n % -2;
        n /= -2;

        if (remainder < 0) {
            remainder += 2;
            n += 1;
        }
        result[index++] = '0' + remainder;
    }

    // Reverse the result string
    for (int i = 0; i < index / 2; ++i) {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }

    result[index] = '\0'; // Null-terminate the string
    return result;

}
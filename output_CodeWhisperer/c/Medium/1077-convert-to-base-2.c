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
        char* result = (char*)malloc(sizeof(char) * 2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    int len = 0;
    int* arr = (int*)malloc(sizeof(int) * 32);
    while (n != 0) {
        arr[len++] = n & 1;
        n = -(n >> 1);
    }
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        result[i] = arr[len - i - 1] + '0';
    }
    result[len] = '\0';
    free(arr);
    return result;
}
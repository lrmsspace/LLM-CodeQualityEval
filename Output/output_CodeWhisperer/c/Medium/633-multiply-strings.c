/**https://leetcode.com/problems/multiply-strings/ */
//Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
// 
//Example 1:
//Input: num1 = "2", num2 = "3"
//Output: "6"
//Example 2:
//Input: num1 = "123", num2 = "456"
//Output: "56088"
// 
//Constraints:
//	1 <= num1.length, num2.length <= 200
//	num1 and num2 consist of digits only.
//	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 + len2;
    int* result = (int*)calloc(len, sizeof(int));
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = result[i + j + 1] + mul;
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    int start = 0;
    while (start < len - 1 && result[start] == 0) {
        start++;
    }
    char* res = (char*)malloc((len - start + 1) * sizeof(char));
    int index = 0;
    for (int i = start; i < len; i++) {
        res[index++] = result[i] + '0';
    }
    res[index] = '\0';
    free(result);
    return res;
}
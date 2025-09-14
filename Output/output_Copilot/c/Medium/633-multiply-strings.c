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
    int *res = (int *)malloc(sizeof(int) * len);
    memset(res, 0, sizeof(int) * len);
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j] += sum / 10;
            res[i + j + 1] = sum % 10;
        }
    }
    char *ret = (char *)malloc(sizeof(char) * (len + 1));
    int index = 0;
    while (index < len && res[index] == 0) {
        index++;
    }
    if (index == len) {
        ret[0] = '0';
        ret[1] = '\0';
        return ret;
    }
    for (int i = index; i < len; i++) {
        ret[i] = res[i] + '0';
    }
    ret[len] = '\0';
    return ret;    
}
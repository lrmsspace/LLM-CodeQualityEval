/**https://leetcode.com/problems/add-strings/ */
//Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
//You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
// 
//Example 1:
//Input: num1 = "11", num2 = "123"
//Output: "134"
//Example 2:
//Input: num1 = "456", num2 = "77"
//Output: "533"
//Example 3:
//Input: num1 = "0", num2 = "0"
//Output: "0"
// 
//Constraints:
//	1 <= num1.length, num2.length <= 104
//	num1 and num2 consist of only digits.
//	num1 and num2 don't have any leading zeros except for the zero itself.
char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int carry = 0;
    char *res = (char*)malloc(strlen(num1) + strlen(num2) + 2);
    int k = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        carry = sum / 10;
        res[k++] = sum % 10 + '0';
    }
    res[k] = '\0';
    reverse(res, 0, k - 1);
    return res;
}
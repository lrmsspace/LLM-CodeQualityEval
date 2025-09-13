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
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 > len2 ? len1 : len2;
    char* result = (char*)malloc(sizeof(char) * (len + 2));
    result[len + 1] = '\0';
    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    int k = len;
    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += num2[j] - '0';
            j--;
        }
        result[k] = sum % 10 + '0';
        carry = sum / 10;
        k--;
    }
    if (carry > 0) {
        result[0] = carry + '0';
        return result;
    } else {
        return result + 1;
    }
    
}
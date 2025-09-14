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
    
    char* result = (char*)calloc(len1 + len2 + 1, sizeof(char));
    int carry = 0;
    
    for (int i = len1 - 1; i >= 0; i--) {
        carry = 0;
        int digit1 = num1[i] - '0';
        
        for (int j = len2 - 1; j >= 0; j--) {
            int digit2 = num2[j] - '0';
            int product = digit1 * digit2 + carry;
            int sum = result[i + j + 1] - '0' + product;
            carry = sum / 10;
            result[i + j + 1] = sum % 10 + '0';
        }
        
        if (carry > 0) {
            result[i] = carry + '0';
        } else {
            result[i] = result[i + 1];
            result[i + 1] = '\0';
        }
    }
    
    return result;
    
}
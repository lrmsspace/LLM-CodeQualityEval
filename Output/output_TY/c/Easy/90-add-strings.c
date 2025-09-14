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
char * addStrings(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;
    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    char* result = (char*)malloc((maxLen + 2) * sizeof(char)); // +2 for possible carry and null terminator
    int k = maxLen + 1;

    result[k--] = '\0'; // Null terminator

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i--] - '0';
        }
        if (j >= 0) {
            sum += num2[j--] - '0';
        }
        result[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // Reverse the result string
    int start = 0;
    int end = maxLen + 1 - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}
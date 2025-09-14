/**https://leetcode.com/problems/add-binary/ */
//Given two binary strings a and b, return their sum as a binary string.
// 
//Example 1:
//Input: a = "11", b = "1"
//Output: "100"
//Example 2:
//Input: a = "1010", b = "1011"
//Output: "10101"
// 
//Constraints:
//	1 <= a.length, b.length <= 104
//	a and b consist only of '0' or '1' characters.
//	Each string does not contain leading zeros except for the zero itself.
char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int carry = 0, sum, i, len_result = max(len_a, len_b) + 1;
    char* result = (char*)malloc((len_result + 1) * sizeof(char));
    result[len_result] = '\0';
    
    for (i = len_a - 1, len_result--; i >= 0 || len_b >= 0 || carry; i--, len_result--) {
        sum = (i >= 0? a[i] - '0' : 0) + (len_b >= 0? b[len_b--] - '0' : 0) + carry;
        carry = sum / 2;
        result[len_result] = '0' + sum % 2;
    }
    
    return result;
}
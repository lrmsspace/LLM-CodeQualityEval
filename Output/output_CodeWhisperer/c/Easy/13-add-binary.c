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
    int len = len_a > len_b ? len_a : len_b;
    char* result = (char*)malloc((len + 2) * sizeof(char));
    result[len + 1] = '\0';
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int bit_a = i < len_a ? a[len_a - 1 - i] - '0' : 0;
        int bit_b = i < len_b ? b[len_b - 1 - i] - '0' : 0;
        int sum = bit_a + bit_b + carry;
        result[len - i] = sum % 2 + '0';
        carry = sum / 2;
    }
    if (carry) {
        result[0] = '1';
        return result;
    } else {
        return result + 1;
    }
    
}
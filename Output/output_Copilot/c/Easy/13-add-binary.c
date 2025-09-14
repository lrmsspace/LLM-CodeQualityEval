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
    char *res = (char *)malloc(sizeof(char) * (len + 2));
    res[len + 1] = '\0';
    int carry = 0;
    int i = len_a - 1;
    int j = len_b - 1;
    int k = len;
    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i--] - '0';
        }
        if (j >= 0) {
            sum += b[j--] - '0';
        }
        res[k--] = sum % 2 + '0';
        carry = sum / 2;
    }
    if (carry) {
        res[k--] = carry + '0';
    }
    return res + k + 1;
}
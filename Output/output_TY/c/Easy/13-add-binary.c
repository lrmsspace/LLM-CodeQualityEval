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
char * addBinary(char * a, char * b){
      int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLength = lenA > lenB ? lenA : lenB;
    int carry = 0;
    int i = lenA - 1;
    int j = lenB - 1;
    int k = maxLength;

    // 分配足够的空间来存储结果字符串
    char* result = (char*)malloc((maxLength + 2) * sizeof(char));
    result[maxLength + 1] = '\0';

    // 从右到左逐位相加
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i--] - '0';
        }
        if (j >= 0) {
            sum += b[j--] - '0';
        }
        carry = sum / 2;
        result[k--] = (sum % 2) + '0';
    }

    // 如果最高位有进位，需要额外处理
    if (carry > 0) {
        result[0] = '1';
        return result;
    } else {
        return result + 1; // 跳过最高位的空位
    }
}
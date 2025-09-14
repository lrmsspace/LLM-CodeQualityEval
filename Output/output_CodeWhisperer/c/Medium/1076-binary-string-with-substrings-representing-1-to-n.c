/**https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/ */
//Given a binary string s and a positive integer n, return true if the binary representation of all the integers in the range [1, n] are substrings of s, or false otherwise.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "0110", n = 3
//Output: true
//Example 2:
//Input: s = "0110", n = 4
//Output: false
// 
//Constraints:
//	1 <= s.length <= 1000
//	s[i] is either '0' or '1'.
//	1 <= n <= 109
bool queryString(char* s, int n) {
    int len = strlen(s);
    for (int i = 1; i <= n; i++) {
        char* binary = (char*)malloc(sizeof(char) * 32);
        int index = 0;
        int num = i;
        while (num > 0) {
            binary[index++] = (num % 2) + '0';
            num /= 2;
        }
        binary[index] = '\0';
        int binaryLen = strlen(binary);
        int j = 0;
        while (j + binaryLen <= len) {
            int k = 0;
            while (k < binaryLen && s[j + k] == binary[k]) {
                k++;
            }
            if (k == binaryLen) {
                break;
            }
            j++;
        }
        if (j + binaryLen > len) {
            free(binary);
            return false;
        }
        free(binary);
    }
    return true;
}
/**https://leetcode.com/problems/restore-ip-addresses/ */
//A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
//	For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
//Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
// 
//Example 1:
//Input: s = "25525511135"
//Output: ["255.255.11.135","255.255.111.35"]
//Example 2:
//Input: s = "0000"
//Output: ["0.0.0.0"]
//Example 3:
//Input: s = "101023"
//Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//Constraints:
//	1 <= s.length <= 20
//	s consists of digits only.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** restoreIpAddresses(char* s, int* returnSize) {
    int n = strlen(s);
    if (n < 4 || n > 12) {
        *returnSize = 0;
        return NULL;
    }
    char** res = (char**)malloc(sizeof(char*) * 100);
    int resSize = 0;
    for (int i = 1; i < 4 && i < n - 2; i++) {
        for (int j = i + 1; j < i + 4 && j < n - 1; j++) {
            for (int k = j + 1; k < j + 4 && k < n; k++) {
                if (n - k > 3) {
                    continue;
                }
                int a = atoi(strndup(s, i));
                int b = atoi(strndup(s + i, j - i));
                int c = atoi(strndup(s + j, k - j));
                int d = atoi(strndup(s + k, n - k));
                if (a <= 255 && b <= 255 && c <= 255 && d <= 255) {
                    char* ip = (char*)malloc(sizeof(char) * (n + 4));
                    sprintf(ip, "%d.%d.%d.%d", a, b, c, d);
                    if (strlen(ip) == n + 3) {
                        res[resSize++] = ip;
                    }
                }
            }
        }
    }
    *returnSize = resSize;
    return res;    
}
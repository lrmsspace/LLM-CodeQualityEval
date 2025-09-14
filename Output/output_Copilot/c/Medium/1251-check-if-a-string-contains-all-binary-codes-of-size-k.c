/**https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/ */
//Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
// 
//Example 1:
//Input: s = "00110110", k = 2
//Output: true
//Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
//Example 2:
//Input: s = "0110", k = 1
//Output: true
//Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
//Example 3:
//Input: s = "0110", k = 2
//Output: false
//Explanation: The binary code "00" is of length 2 and does not exist in the array.
// 
//Constraints:
//	1 <= s.length <= 5 * 105
//	s[i] is either '0' or '1'.
//	1 <= k <= 20
bool hasAllCodes(char* s, int k) {
    int n = strlen(s);
    if (n < k) return false;
    int m = 1 << k;
    bool *b = (bool *)malloc(m * sizeof(bool));
    memset(b, 0, m * sizeof(bool));
    int mask = m - 1;
    int v = 0;
    for (int i = 0; i < n; i++) {
        v = (v << 1) & mask;
        v |= s[i] - '0';
        if (i >= k - 1) {
            b[v] = true;
        }
    }
    for (int i = 0; i < m; i++) {
        if (!b[i]) {
            free(b);
            return false;
        }
    }
    free(b);
    return true;    
}
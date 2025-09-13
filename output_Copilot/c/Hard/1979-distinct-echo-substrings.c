/**https://leetcode.com/problems/distinct-echo-substrings/ */
//Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).
// 
//Example 1:
//Input: text = "abcabcabc"
//Output: 3
//Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
//Example 2:
//Input: text = "leetcodeleetcode"
//Output: 2
//Explanation: The 2 substrings are "ee" and "leetcodeleetcode".
// 
//Constraints:
//	1 <= text.length <= 2000
//	text has only lowercase English letters.
int distinctEchoSubstrings(char* text) {
       int n = strlen(text);
        int* base = (int*)malloc(n * sizeof(int));
        base[0] = 1;
        for (int i = 1; i < n; i++) {
            base[i] = base[i - 1] * 26;
        }
        int* hash = (int*)malloc((n + 1) * sizeof(int));
        hash[0] = 0;
        for (int i = 0; i < n; i++) {
            hash[i + 1] = hash[i] * 26 + text[i] - 'a';
        }
        int result = 0;
        for (int len = 2; len <= n; len += 2) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len / 2;
                int hash1 = hash[j] - hash[i] * base[j - i];
                int hash2 = hash[i + len] - hash[j] * base[len / 2];
                if (hash1 == hash2) {
                    result++;
                }
            }
        }
        free(base);
        free(hash);
        return result;     
}
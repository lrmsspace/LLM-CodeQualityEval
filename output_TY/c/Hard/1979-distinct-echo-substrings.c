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
int distinctEchoSubstrings(char * text){
    int n = strlen(text);
    int ans = 0;
    int mask[n][n];
    memset(mask, 0, sizeof(mask));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            mask[i][j] = mask[i][j - 1] ^ (1 << (text[j] - 'a'));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int m = mask[i][j];
            int k = 0;
            while (i + k <= j) {
                if ((m >> (text[i + k] - 'a')) & 1) {
                    k++;
                } else {
                    break;
                }
            }
        }
    }
    return ans;
}
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
    int ans = 0;
    for (int len = 1; len <= n / 2; ++len) {
        unordered_set<string> seen;
        for (int i = 0; i <= n - 2 * len; ++i) {
            string s = string(text + i, len);
            if (seen.count(s)) continue;
            seen.insert(s);
            if (equal(text + i, text + i + len, text + i + len, text + i + 2 * len))
                ++ans;
        }
    }
    return ans;
}

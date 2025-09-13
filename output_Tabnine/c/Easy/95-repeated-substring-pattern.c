/**https://leetcode.com/problems/repeated-substring-pattern/ */
//Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
// 
//Example 1:
//Input: s = "abab"
//Output: true
//Explanation: It is the substring "ab" twice.
//Example 2:
//Input: s = "aba"
//Output: false
//Example 3:
//Input: s = "abcabcabcabc"
//Output: true
//Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of lowercase English letters.
bool repeatedSubstringPattern(char* s) {
    int n = strlen(s);
    for (int len = 1; len <= n / 2; ++len) {
        if (n % len == 0) {
            char* sub = s;
            for (int i = 1; i * len < n; ++i) {
                if (memcmp(sub, sub + len, len)!= 0) {
                    break;
                }
                sub += len;
            }
            if (sub == s + n) {
                return true;
            }
        }
    }
    return false;
}
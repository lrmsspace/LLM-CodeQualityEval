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
    int len = strlen(s);
    for (int i = 1; i <= len / 2; i++) {
        if (len % i == 0) {
            int j = i;
            while (j < len && s[j] == s[j % i]) j++;
            if (j == len) return true;
        }
    }
    return false;    
}
/**https://leetcode.com/problems/wildcard-matching/ */
//Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
//	'?' Matches any single character.
//	'*' Matches any sequence of characters (including the empty sequence).
//The matching should cover the entire input string (not partial).
// 
//Example 1:
//Input: s = "aa", p = "a"
//Output: false
//Explanation: "a" does not match the entire string "aa".
//Example 2:
//Input: s = "aa", p = "*"
//Output: true
//Explanation: '*' matches any sequence.
//Example 3:
//Input: s = "cb", p = "?a"
//Output: false
//Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
// 
//Constraints:
//	0 <= s.length, p.length <= 2000
//	s contains only lowercase English letters.
//	p contains only lowercase English letters, '?' or '*'.
bool isMatch(char * s, char * p){
    int len_s = strlen(s);
    int len_p = strlen(p);
    int i = 0, j = 0;
    while (i < len_s && j < len_p) {
        if (p[j] == '*') {
            j++;
            while (j < len_p && p[j] == '*') {
                j++;
            }
            if (j ==len_p) {
                return true;
            }
        }
    }
    if (i == len_s) {
        while (j < len_p) {
            if (p[j] != '*') {
                return false;
            }
            j++;
        }
        return true;
    }
    return false;
}
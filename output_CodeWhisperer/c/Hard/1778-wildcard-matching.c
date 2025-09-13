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
bool isMatch(char* s, char* p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    int sIndex = 0;
    int pIndex = 0;
    int starIndex = -1;
    int sTempIndex = -1;

    while (sIndex < sLen) {
        if (pIndex < pLen && (p[pIndex] == '?' || s[sIndex] == p[pIndex])) {
            sIndex++;
            pIndex++;
        } else if (pIndex < pLen && p[pIndex] == '*') {
            starIndex = pIndex;
            sTempIndex = sIndex;
            pIndex++;
        } else if (starIndex == -1) {
            return false;
        } else {
            pIndex = starIndex + 1;
            sIndex = sTempIndex + 1;
            sTempIndex = sIndex;
        }
    }

    while (pIndex < pLen && p[pIndex] == '*') {
        pIndex++;
    }

    return pIndex == pLen;
    
}
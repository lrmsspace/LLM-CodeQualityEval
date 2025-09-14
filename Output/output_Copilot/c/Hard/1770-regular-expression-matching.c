/**https://leetcode.com/problems/regular-expression-matching/ */
//Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
//	'.' Matches any single character.​​​​
//	'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string (not partial).
// 
//Example 1:
//Input: s = "aa", p = "a"
//Output: false
//Explanation: "a" does not match the entire string "aa".
//Example 2:
//Input: s = "aa", p = "a*"
//Output: true
//Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
//Example 3:
//Input: s = "ab", p = ".*"
//Output: true
//Explanation: ".*" means "zero or more (*) of any character (.)".
// 
//Constraints:
//	1 <= s.length <= 20
//	1 <= p.length <= 20
//	s contains only lowercase English letters.
//	p contains only lowercase English letters, '.', and '*'.
//	It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
bool isMatch(char* s, char* p) {
    int i = 0, j = 0;
    while (s[i] != '\0' && p[j] != '\0') {
        if (p[j + 1] == '*') {
            if (p[j] == '.') {
                while (s[i] != '\0') {
                    if (isMatch(s + i, p + j + 2)) {
                        return true;
                    }
                    i++;
                }
                return isMatch(s + i, p + j + 2);
            } else {
                if (s[i] == p[j]) {
                    while (s[i] == p[j]) {
                        if (isMatch(s + i, p + j + 2)) {
                            return true;
                        }
                        i++;
                    }
                    return isMatch(s + i, p + j + 2);
                } else {
                    return isMatch(s + i, p + j + 2);
                }
            }
        } else {
            if (p[j] == '.' || s[i] == p[j]) {
                i++;
                j++;
            } else {
                return false;
            }
        }
    }
    if (s[i] == '\0') {
        if (p[j] == '\0') {
            return true;
        } else {
            if (p[j + 1] == '*') {
                return isMatch(s + i, p + j + 2);
            } else {
                return false;
            }
        }
    } else {
        return false;
    }    
}
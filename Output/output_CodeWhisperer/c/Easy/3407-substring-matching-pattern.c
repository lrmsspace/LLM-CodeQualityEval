/*
 You are given a string s and a pattern string p, where p contains exactly one '*' character.
 The '*' in p can be replaced with any sequence of zero or more characters.
 Return true if p can be made a substring of s, and false otherwise.
 Example 1:
 Input: s = "leetcode", p = "ee*e"
 Output: true
 Explanation:
 By replacing the '*' with "tcod", the substring "eetcode" matches the pattern.
 Example 2:
 Input: s = "car", p = "c*v"
 Output: false
 Explanation:
 There is no substring matching the pattern.
 Example 3:
 Input: s = "luck", p = "u*"
 Output: true
 Explanation:
 The substrings "u", "uc", and "uck" match the pattern.
 Constraints:
 1 <= s.length <= 50
 1 <= p.length <= 50 
 s contains only lowercase English letters.
 p contains only lowercase English letters and exactly one '*'
*/

bool hasMatch(char* s, char* p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < sLen && j < pLen) {
        if (s[i] == p[j] || p[j] == '?') {
            i++;
            j++;
        } else if (p[j] == '*') {
            k = i;
            while (k < sLen) {
                if (hasMatch(s + k, p + j + 1)) {
                    return true;
                }
                k++;
            }
            return false;
        } else {
            return false;
        }
    }
    if (i == sLen && j == pLen) {
        return true;
    } else if (i == sLen && j < pLen) {
        while (j < pLen) {
            if (p[j] != '*') {
                return false;
            }
            j++;
        }
        return true;
    } else {
        return false;
    }
}    
}
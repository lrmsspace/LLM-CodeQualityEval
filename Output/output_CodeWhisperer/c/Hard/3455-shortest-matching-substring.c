/*
 You are given a string s and a pattern string p, where p contains exactly two '*' characters.
 The '*' in p matches any sequence of zero or more characters.
 Return the length of the shortest substring in s that matches p. If there is no such substring, return -1.
 Note: The empty substring is considered valid.
 Example 1:
 Input: s = "abaacbaecebce", p = "ba*c*ce"
 Output: 8
 Explanation:
 The shortest matching substring of p in s is "baecebce".
 Example 2:
 Input: s = "baccbaadbc", p = "cc*baa*adb"
 Output: -1
 Explanation:
 There is no matching substring in s.
 Example 3:
 Input: s = "a", p = "**"
 Output: 0
 Explanation:
 The empty substring is the shortest matching substring.
 Example 4:
 Input: s = "madlogic", p = "*adlogi*"
 Output: 6
 Explanation:
 The shortest matching substring of p in s is "adlogi".
 Constraints:
 1 <= s.length <= 105
 2 <= p.length <= 105
 s contains only lowercase English letters.
 p contains only lowercase English letters and exactly two '*'.
*/

int shortestMatchingSubstring(char* s, char* p) {
    int sLen = strlen(s), pLen = strlen(p);
    int left = 0, right = sLen - 1;
    int minLen = -1;
    
    while (left <= right) {
        int i = 0, j = 0;
        while (i < pLen && j < sLen) {
            if (p[i] == '*') {
                int k = j;
                while (k <= right && s[k] != p[i + 1]) k++;
                if (k > right) break;
                j = k + 1;
                i += 2;
            } else {
                if (s[j] != p[i]) break;
                j++;
                i++;
            }
        }
        if (i == pLen) {
            int len = j - left;
            if (minLen == -1 || len < minLen) minLen = len;
        }
        left++;
    }
    
    return minLen;    
}
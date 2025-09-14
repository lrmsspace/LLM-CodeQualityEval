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

class Solution {
public:
    int shortestMatchingSubstring(string s, string p) {
        int n = s.size(), m = p.size();
        int i = 0, j = 0;
        int left = -1, right = -1;
        while (i < n) {
            while (i < n && j < m && (s[i] == p[j] || p[j] == '*')) {
                if (p[j] == '*') left = j;
                ++j;
                ++i;
            }
            if (j == m) {
                if (left == -1) return 0;
                right = j - 1;
                while (left > 0 && p[left] == '*') --left;
                while (right > 0 && p[right] == '*') --right;
                return right - left + 1;
            }
            i = i - j + 1;
            j = 0;
            left = -1;
        }
        return -1;

    }
};
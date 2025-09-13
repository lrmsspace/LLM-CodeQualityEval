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
    public int shortestMatchingSubstring(String s, String p) {
        int n = s.length();
        int m = p.length();
        int[] next = new int[m];
        int j = -1;
        for (int i = 1; i < m; i++) {
            while (j != -1 && p.charAt(i) != p.charAt(j + 1)) {
                j = next[j];
            }
            if (p.charAt(i) == p.charAt(j + 1)) {
                j++;
            }
            next[i] = j;
        }
        int[] f = new int[n];
        j = -1;
        for (int i = 0; i < n; i++) {
            while (j != -1 && s.charAt(i) != p.charAt(j + 1)) {
                j = next[j];
            }
            if (s.charAt(i) == p.charAt(j + 1)) {
                j++;
            }
            f[i] = j;
            if (j == m - 1) {
                return i - m + 2;
            }
        }
        return -1;        
    }
}
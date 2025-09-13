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
        int m = s.length(), n = p.length();
        if (n < 2) return -1;
        
        int[] count = new int[26];
        int[] pCount = new int[26];
        for (int i = 0; i < n - 2; i += 2) {
            pCount[p.charAt(i) - 'a']++;
            pCount[p.charAt(i + 1) - 'a']++;
        }
        
        int start = 0, minLen = Integer.MAX_VALUE;
        int countMatch = 0;
        for (int end = 0; end < m; end++) {
            count[s.charAt(end) - 'a']++;
            if (count[s.charAt(end) - 'a'] <= pCount[s.charAt(end) - 'a']) countMatch++;
            
            if (end - start + 1 >= n - 2 && countMatch == n / 2) {
                while (count[s.charAt(start) - 'a'] > pCount[s.charAt(start) - 'a'] || countMatch!= n / 2) {
                    if (count[s.charAt(start) - 'a'] > pCount[s.charAt(start) - 'a']) countMatch--;
                    count[s.charAt(start) - 'a']--;
                    start++;
                }
                minLen = Math.min(minLen, end - start + 1);
            }
        }
        return minLen == Integer.MAX_VALUE? -1 : minLen;
        
    }
}
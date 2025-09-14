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
        int m = s.length(), n = p.length();
        if (n < 2) return -1;
        
        vector<int> count(26, 0);
        for (int i = 1; i < n - 1; ++i) {
            if (p[i] == '*') count[p[i - 1] - 'a']++;
            else if (p[i] == s[0]) count[p[i - 1] - 'a']++;
        }
        
        int left = 0, right = 0, ans = INT_MAX;
        while (right < m) { 
            if (count[s[right] - 'a']-- > 0) {
                while (left <= right && count[s[left] - 'a'] < 0) {
                    count[s[left++] - 'a']++;
                }
                ans = min(ans, right - left + 1);
            } else {
                if (p[right - left + 1] == '*') count[s[left++] - 'a']++;
                else if (p[right - left + 1] == s[right]) left++;
                else return -1;
            }
            right++;
    
            if (ans == m - n + 2) break;
        }
        return ans == INT_MAX? -1 : ans;
        
    }
};
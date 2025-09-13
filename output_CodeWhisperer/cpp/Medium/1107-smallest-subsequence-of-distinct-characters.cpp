/**https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ */
//Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        for (char c : s) {
            count[c - 'a']++;
        }
        string res = "";
        for (char c : s) {
            count[c - 'a']--;
            if (visited[c - 'a']) {
                continue;
            }
            while (res.length() > 0 && res.back() > c && count[res.back() - 'a'] > 0) {
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(c);
            visited[c - 'a'] = true;
        }
        return res;       
    }
};
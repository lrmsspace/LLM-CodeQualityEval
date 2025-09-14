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
        int n = s.size();
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++)
            last[s[i] - 'a'] = i;
        vector<bool> vis(26, false);
        string res;
        for (int i = 0; i < n; i++)
        {
            if (vis[s[i] - 'a'])
                continue;
            while (res.size() && res.back() > s[i] && last[res.back() - 'a'] > i)
            {
                vis[res.back() - 'a'] = false;
                res.pop_back();
            }
        }
        return res;
    }
};
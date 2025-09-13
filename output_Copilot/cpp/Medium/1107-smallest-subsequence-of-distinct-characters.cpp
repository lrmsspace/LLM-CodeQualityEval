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
        vector<int> last(26, -1);
        vector<bool> seen(26, false);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (seen[s[i] - 'a']) {
                continue;
            }
            while (!st.empty() && st.top() > s[i] - 'a' && i < last[st.top()]) {
                seen[st.top()] = false;
                st.pop();
            }
            st.push(s[i] - 'a');
            seen[s[i] - 'a'] = true;
        }
        string ans;
        while (!st.empty()) {
            ans += st.top() + 'a';
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;        
    }
};
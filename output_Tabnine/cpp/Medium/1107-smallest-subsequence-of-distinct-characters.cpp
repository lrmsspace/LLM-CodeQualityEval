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
        for (char c : s)
            count[c - 'a']++;
        
        stack<char> st;
        unordered_set<char> used;
        
        for (char c : s) {
            count[c - 'a']--;
            if (used.count(c)) continue;
            
            while (!st.empty() && st.top() > c && count[st.top() - 'a'] > 0) {
                used.erase(st.top());
                st.pop();
            }
            
            st.push(c);
            used.insert(c);
        }
        
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        return res;
        
    }
};
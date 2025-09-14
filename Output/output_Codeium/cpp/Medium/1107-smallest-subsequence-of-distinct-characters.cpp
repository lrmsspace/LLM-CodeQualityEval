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
        vector<int> lastIndex(26, -1);
        vector<bool> inStack(26, false);
        stack<char> st;
        
        for (int i = 0; i < s.size(); ++i) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            int currentChar = s[i] - 'a';
            if (inStack[currentChar]) continue;

            while (!st.empty() && st.top() > s[i] && lastIndex[st.top() - 'a'] > i) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(s[i]);
            inStack[currentChar] = true;
        }
        
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;

    }
};
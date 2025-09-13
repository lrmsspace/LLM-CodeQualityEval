/**https://leetcode.com/problems/last-substring-in-lexicographical-order/ */
//Given a string s, return the last substring of s in lexicographical order.
// 
//Example 1:
//Input: s = "abab"
//Output: "bab"
//Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
//Example 2:
//Input: s = "leetcode"
//Output: "tcode"
// 
//Constraints:
//	1 <= s.length <= 4 * 105
//	s contains only lowercase English letters.
class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        vector<int> next(n);
        for (int i = n - 1; i >= 0; --i) {
            next[i] = i + 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] > s[j]) {
                    next[i] = j;
                    break;
                }
            }
        }
        
        string res = "";
        for (int i = 0; i < n; ++i) {
            res += s[next[i] - 1];
        }
        return res;
        
    }
};
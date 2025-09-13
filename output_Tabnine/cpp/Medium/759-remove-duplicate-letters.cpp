/**https://leetcode.com/problems/remove-duplicate-letters/ */
//Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last[26] = {}, cnt[26] = {};
        bool inStack[26] = {};
        string res;
        for (char c : s) {
            cnt[c - 'a']++;
        }
        for (char c : s) {
            if (inStack[c - 'a']) {
                cnt[c - 'a']--;
                continue;
            }
            while (!res.empty() && res.back() > c && cnt[res.back() - 'a'] > 0) {
                inStack[res.back() - 'a'] = false;
                res.pop_back();
            }
            res += c;
            inStack[c - 'a'] = true;
        }
        return res;
        
    }
};
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
        string seen = "", res = "";
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        for (char c : s) {
            freq[c - 'a']--;
            if (seen.find(c) != string::npos) continue;
            while (res.back() > c && freq[res.back() - 'a']) {
                seen.erase(seen.find(res.back()));
                res.pop_back();
            }
            res.push_back(c);
            seen += c;
        }
        return res;
    }
};
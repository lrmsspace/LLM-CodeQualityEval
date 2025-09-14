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
        int freq[26] = {0};
        for(char c : s) freq[c - 'a']++;
        string ans = "";
        int vis[26] = {0};
        for(char c : s){
            freq[c - 'a']--;
            if(vis[c - 'a']) continue;
            while(ans.size() && ans.back() > c && freq[ans.back() -'a'] > 0){
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
        }
        return ans;
    }
};
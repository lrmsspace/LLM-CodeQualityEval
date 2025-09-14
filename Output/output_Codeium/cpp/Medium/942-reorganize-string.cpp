/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        for (auto c : s) count[c-'a']++;
        priority_queue<pair<int, char>> pq;
        for (int i=0; i<26; ++i) if (count[i]) pq.push({count[i], i+'a'});
        string res;
        while (pq.size() > 1) {
            auto p1 = pq.top(); pq.pop();
            auto p2 = pq.top(); pq.pop();
            res += p1.second;
            res += p2.second;
            if (--p1.first) pq.push(p1);
            if (--p2.first) pq.push(p2);
        }
        if (pq.size()) return "";
        return res;
    }
};
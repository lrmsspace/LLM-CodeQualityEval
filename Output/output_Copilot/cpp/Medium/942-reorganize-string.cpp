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
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > (n + 1) / 2) {
                return "";
            }
            if (cnt[i] > 0) {
                pq.push({cnt[i], i + 'a'});
            }
        }
        string ans;
        while (pq.size() >= 2) {
            auto [cnt1, c1] = pq.top(); pq.pop();
            auto [cnt2, c2] = pq.top(); pq.pop();
            ans.push_back(c1);
            ans.push_back(c2);
            if (--cnt1 > 0) {
                pq.push({cnt1, c1});
            }
            if (--cnt2 > 0) {
                pq.push({cnt2, c2});
            }
        }
        if (!pq.empty()) {
            ans.push_back(pq.top().second);
        }
        return ans;        
    }
};
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
        unordered_map<char, int> m;
        for (auto c : s) m[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto p : m) pq.push(make_pair(p.second, p.first));
        string ans;
        while (pq.size() > 1) {
            auto p1 = pq.top(); pq.pop();
            auto p2 = pq.top(); pq.pop();
            ans += p1.second;
            ans += p2.second;
            if (--p1.first > 0) pq.push(p1);
            if (--p2.first> 0) pq.push(p2);
        }
        if (pq.size() == 0) return ans;
        else if (pq.top().first > 1) return "";
        else return ans + pq.top().second;
        return ans;

    }
};
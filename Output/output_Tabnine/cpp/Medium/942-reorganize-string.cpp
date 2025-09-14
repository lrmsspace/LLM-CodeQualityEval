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
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        for (auto &[c, count] : freq) {
            pq.push({count, c});
        }
        
        string res;
        while (!pq.empty() && pq.top().first > 1) {

            pair<int, char> top = pq.top();
            pq.pop();
            res += top.second;
            top.first--;
            if (top.first > 0) {
                pq.push(top);
            }
            
            if (!pq.empty()) {
                pair<int, char> next = pq.top();
                pq.pop();
                res += next.second;
                next.first--;
                if (next.first > 0) {
                    pq.push(next);
                }
            }
            
            if (pq.empty()) {
                return "";
            }
        }

        while (!pq.empty()) {
            pair<int, char> top = pq.top();
            pq.pop();
            res += top.second;
            if (top.first > 1) {
                return "";
            }
        }
        
        return res;
        
    }
};
/**https://leetcode.com/problems/find-the-shortest-superstring/ */
//Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
//You may assume that no string in words is a substring of another string in words.
// 
//Example 1:
//Input: words = ["alex","loves","leetcode"]
//Output: "alexlovesleetcode"
//Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
//Example 2:
//Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
//Output: "gctaagttcatgcatc"
// 
//Constraints:
//	1 <= words.length <= 12
//	1 <= words[i].length <= 20
//	words[i] consists of lowercase English letters.
//	All the strings of words are unique.
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        vector<vector<string>> path(1 << n, vector<string>(n));
        dp[0][0] = 0;
        for(int mask = 0; mask < (1 << n); ++mask) {
            for(int i = 0; i < n; ++i) {
                if(((mask >> i) & 1) == 0) continue;
                for(int j = 0; j < n; ++j) {
                    if(i == j || ((mask >> j) & 1) == 0) continue;
                    int new_mask = mask ^ (1 << i);
                    int new_len = dp[new_mask][j] + overlap(words[j], words[i]);
                    if(new_len < dp[mask][i]) {
                        dp[mask][i] = new_len;
                        path[mask][i] = path[new_mask][j] + words[i].substr(words[j].size() - overlap(words[j], words[i]));
                    }
                }
            }
        }
        string res = "";
        for(int i = 0; i < n; ++i) {
            if(dp[(1 << n) - 1][i] < res.size() || res.empty()) {
                res = path[(1 << n) - 1][i];
            }
        }
        return res;
        
    }
    
    int overlap(string a, string b) {
        int res = 0;
        for(int i = 1; i < a.size(); ++i) {
            if(a.substr(i) == b.substr(0, a.size() - i)) {
                res = max(res, i);
            }
        }
        return res;
    }
};
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
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                for (int k = 1; k <= words[i].size(); ++k) {
                    if (words[j].rfind(words[i].substr(0, k)) == 0) {
                        overlap[i][j] = k;
                    }
                }
            }
        }
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            dp[1 << i][i] = words[i].size();
        }
        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) continue;
                for (int j = 0; j < n; ++j) {
                    if (mask & (1 << j)) continue;
                    if (dp[mask | (1 << j)][j] > dp[mask][i] + (int)words[j].size() - overlap[i][j]) {
                        dp[mask | (1 << j)][j] = dp[mask][i] + (int)words[j].size() - overlap[i][j];
                        parent[mask | (1 << j)][j] = i;
                    }
                }
            }
        }
        int last = min_element(dp.back().begin(), dp.back().end()) - dp.back().begin();
        int mask = (1 << n) - 1;
        string res;
        while (mask) {
            int prev = parent[mask][last];
            if (prev == -1) {
                res = words[last] + res;
            } else {
                res = words[last].substr(overlap[prev][last]) + res;
            }
            mask ^= (1 << last);
            last = prev;
        }
        return res;        
    }
};
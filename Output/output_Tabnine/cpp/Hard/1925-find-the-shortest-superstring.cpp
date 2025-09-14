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
        int m = words[0].size();
        vector<vector<int>> dp(n, vector<int>(1 << n, m + 1));
        vector<int> parent(n, -1);
        for (int mask = 1; mask < (1 << n); ++mask) {
            int len = m;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    for (int j = 0; j < n; ++j) {
                        if ((mask >> j) & 1 && j!= i) {
                            int newLen = max(newLen, dp[j][mask ^ (1 << i)]);
                        }
                    }
                    len = min(len, newLen + m - words[i].size());
                }
            }
            dp[i][mask] = len;
        }
        int maxLen = 0;
        int maxMask = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            if (dp[i][mask] > maxLen) {
                maxLen = dp[i][mask];
                maxMask = mask;
            }
        }
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            if ((maxMask >> i) & 1) {
                ans[i] = words[i];
            }
        }
        for (int mask = (1 << n) - 1; mask > 0; --mask) {
            int len = dp[parent[mask]][mask ^ (1 << parent[mask])];
            ans[parent[mask]] += words[mask & ~(1 << parent[mask])];
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1 && (mask ^ (1 << i)) == (1 << parent[mask])) {
                    dp[i][mask] = len;
                    parent[mask] = i;
                    break;
                }
            }
        }
        string res = ans[0];
        for (int i = 1; i < n; ++i) {
            res += words[i];
        }
        return res;
        
    }
};
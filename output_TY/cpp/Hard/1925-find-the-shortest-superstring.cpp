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
        vector<vector<int>> dp(1 << n, vector<int>(n, 0));
        vector<vector<int>> g(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < words[j].size(); ++k)
                    if (words[i].find(words[j].substr(k)) != string::npos)
                        g[i][j] = words[j].size() - k;

        for (int i = 0; i < n; ++i)
            dp[1 << i][i] = words[i].size();

        for (int s = 1; s < (1 << n); ++s)
            for (int i = 0; i < n; ++i)
                if (s & (1 << i))
                {
                    int s1 = s ^ (1 << i);
                    for (int j = 0; j < n; ++j)
                        if (s1 & (1 << j))
                            dp[s][i] = max(dp[s][i], dp[s1][j] + g[j][i]);
                }
                return words[0];
    }
};
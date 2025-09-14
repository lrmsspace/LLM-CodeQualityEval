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
    public String shortestSuperstring(String[] words) {
     
        int n = words.length;
        int[][] dp = new int[1 << n][n];
        int[][] path = new int[1 << n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    String s1 = words[i];
                    String s2 = words[j];
                    for (int k = 0; k < s2.length(); k++) {
                        if (s1.charAt(s1.length() - 1) == s2.charAt(k)) {
                            int mask = 1 << i | 1 << j;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = words[i].length();
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0)continue;
                for (int j = 0; j < n; j++) {
                    if (i != j && (mask & (1 << j)) > 0) {
                        int newMask = mask ^ (1 << i);
                        int temp = dp[newMask][j] + getCommonLength(words[i], words[j]);
                        if (temp > dp[mask][i]) {
                            dp[mask][i] = temp;
                           path[mask][i] = j;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, dp[(1 << n) - 1][i]);
        }
        StringBuilder sb = new StringBuilder();
        int cur = (1 << n) - 1;
        while (cur > 0) {
            int pre = path[cur][sb.length()];
            sb.insert(0, words[pre]);
            cur ^= 1 << pre;
        }
        return sb.toString();
    
    }
}
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
        int[][] dp = new int[n][n];
        int[] ends = new int[n];
        
        for (int i = 0; i < n; i++) {
            ends[i] = words[i].length();
            for (int j = i + 1; j < n; j++) {
                int len = 0;
                for (int k = 0; k < words[i].length() && k < words[j].length(); k++) {
                    if (words[i].charAt(words[i].length() - 1 - k) == words[j].charAt(k)) {
                        len = k + 1;
                        break;
                    }
                }
                dp[i][j] = len;
            }
        }
        
        int[][] path = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0) {
                    path[i][j] = -1;
                } else {
                    path[i][j] = j;
                }
            }
        }
        
        int maxLength = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (ends[i] > maxLength) {
                maxLength = ends[i];
                start = i;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        sb.append(words[start]);
        
        while (start!= -1) {
            int end = start;
            for (int i = 0; i < n; i++) {
                if (dp[start][i] > 0 && ends[i] + dp[start][i] > maxLength) {
                    maxLength = ends[i] + dp[start][i];
                    end = i;
                }
            }
            sb.insert(0, words[end]);
            start = path[start][end];
        }
        
        return sb.toString();
        
    }
}
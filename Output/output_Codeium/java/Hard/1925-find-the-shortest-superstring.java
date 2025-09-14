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
        int[][] overlap = new int[n][n];
        
        // Calculate overlap between each pair of words
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    overlap[i][j] = calculateOverlap(words[i], words[j]);
                }
            }
        }

        // Use DP to find shortest superstring
        int[][] dp = new int[1 << n][n];
        int[][] parent = new int[1 << n][n];
        
        for (int mask = 0; mask < (1 << n); mask++) {
            Arrays.fill(dp[mask], Integer.MAX_VALUE / 2);
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) > 0) {
                    int prevMask = mask ^ (1 << i);
                    if (prevMask == 0) {
                        dp[mask][i] = words[i].length();
                    } else {
                        for (int j = 0; j < n; j++) {
                            if ((prevMask & (1 << j)) > 0) {
                                int value = dp[prevMask][j] + words[i].length() - overlap[j][i];
                                if (value < dp[mask][i]) {
                                    dp[mask][i] = value;
                                    parent[mask][i] = j;
                                }
                            }
                        }
                    }
                }
            }
        }

        // Find the end of the shortest superstring
        int minLength = Integer.MAX_VALUE;
        int lastIndex = 0;
        for (int i = 0; i < n; i++) {
            if (dp[(1 << n) - 1][i] < minLength) {
                minLength = dp[(1 << n) - 1][i];
                lastIndex = i;
            }
        }

        // Reconstruct the shortest superstring
        StringBuilder superstring = new StringBuilder();
        int mask = (1 << n) - 1;
        while (mask > 0) {
            int prevIndex = parent[mask][lastIndex];
            if (mask == (1 << lastIndex)) {
                superstring.insert(0, words[lastIndex]);
            } else {
                superstring.insert(0, words[lastIndex].substring(overlap[prevIndex][lastIndex]));
            }
            mask ^= (1 << lastIndex);
            lastIndex = prevIndex;
        }
        
        return superstring.toString();
    }
    
    private int calculateOverlap(String a, String b) {
        int maxOverlap = 0;
        for (int len = 1; len <= Math.min(a.length(), b.length()); len++) {
            if (a.endsWith(b.substring(0, len))) {
                maxOverlap = len;
            }
        }
        return maxOverlap;
    }
    
}
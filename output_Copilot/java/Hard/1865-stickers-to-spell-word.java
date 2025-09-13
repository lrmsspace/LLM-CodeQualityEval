/**https://leetcode.com/problems/stickers-to-spell-word/ */
//We are given n different types of stickers. Each sticker has a lowercase English word on it.
//You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
//Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.
//Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and target was chosen as a concatenation of two random words.
// 
//Example 1:
//Input: stickers = ["with","example","science"], target = "thehat"
//Output: 3
//Explanation:
//We can use 2 "with" stickers, and 1 "example" sticker.
//After cutting and rearrange the letters of those stickers, we can form the target "thehat".
//Also, this is the minimum number of stickers necessary to form the target string.
//Example 2:
//Input: stickers = ["notice","possible"], target = "basicbasic"
//Output: -1
//Explanation:
//We cannot form the target "basicbasic" from cutting letters from the given stickers.
// 
//Constraints:
//	n == stickers.length
//	1 <= n <= 50
//	1 <= stickers[i].length <= 10
//	1 <= target.length <= 15
//	stickers[i] and target consist of lowercase English letters.
class Solution {
    public int minStickers(String[] stickers, String target) {
        int n = stickers.length;
        int m = target.length();
        int[][] stickerCount = new int[n][26];
        for (int i = 0; i < n; i++) {
            for (char c : stickers[i].toCharArray()) {
                stickerCount[i][c - 'a']++;
            }
        }
        int[][] dp = new int[1 << m][n + 1];
        for (int i = 0; i < (1 << m); i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        dp[0][0] = 0;
        for (int mask = 0; mask < (1 << m); mask++) {
            for (int i = 0; i < n; i++) {
                if (dp[mask][i] == Integer.MAX_VALUE) continue;
                int nextMask = mask;
                for (int j = 0; j < 26; j++) {
                    if (stickerCount[i][j] == 0) continue;
                    for (int k = 0; k < stickerCount[i][j]; k++) {
                        for (int l = 0; l < m; l++) {
                            if ((mask & (1 << l)) == 0 && target.charAt(l) - 'a' == j) {
                                nextMask |= (1 << l);
                                break;
                            }
                        }
                    }
                }
                dp[nextMask][i + 1] = Math.min(dp[nextMask][i + 1], dp[mask][i] + 1);
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i <= n; i++) {
            ans = Math.min(ans, dp[(1 << m) - 1][i]);
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;        
    }
}
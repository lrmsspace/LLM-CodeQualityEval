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
        int targetLen = target.length();
        int[] targetCount = new int[26];
        for (char c : target.toCharArray()) {
            targetCount[c - 'a']++;
        }
        
        int[][] dp = new int[1 << n][targetLen];
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < targetLen; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        
        for (int i = 0; i < (1 << n); i++) {
            if (isTargetCovered(i, targetCount, dp[i][0], stickers)) {
                dp[i][0] = 0;
            }
        }
        
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 1; j < targetLen; j++) {
                for (int k = 0; k < n; k++) {
                    if ((i & (1 << k)) == 0) {
                        continue;
                    }
                    if (isTargetCovered(i ^ (1 << k), targetCount, dp[i][j - 1] + 1, stickers)) {
                        dp[i][j] = Math.min(dp[i][j], dp[i ^ (1 << k)][j - 1] + 1);
                    }
                }
            }
        }
        
        return dp[(1 << n) - 1][targetLen - 1];
    }
}
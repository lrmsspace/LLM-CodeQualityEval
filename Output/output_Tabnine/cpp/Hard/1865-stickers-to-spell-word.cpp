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
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        int targetLength = target.length();
        vector<int> targetCount(26, 0);
        for (char c : target) {
            targetCount[c - 'a']++;
        }
        vector<vector<int>> dp(1 << n, vector<int>(targetLength + 1, INT_MAX));
        dp[0][0] = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) {
                    continue;
                }
                int stickerLength = stickers[i].length();
                for (int j = 0; j < stickerLength; j++) {
                    int charIndex = stickers[i][j] - 'a';
                    if (targetCount[charIndex] > 0) {
                        int newMask = mask ^ (1 << i);
                        dp[newMask][j + 1] = min(dp[newMask][j + 1], dp[mask][j] + 1);
                        targetCount[charIndex]--;
                    }
                }
            }
        }
        int minStickers = INT_MAX;
        for (int i = 0; i <= targetLength; i++) {
            minStickers = min(minStickers, dp[(1 << n) - 1][i]);
        }
        return minStickers == INT_MAX? -1 : minStickers;
    }
};
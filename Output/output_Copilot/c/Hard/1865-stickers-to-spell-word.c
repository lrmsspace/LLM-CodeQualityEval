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


        int minStickers(char** stickers, int stickersSize, char* target) {
            int targetLen = strlen(target);
            int targetMask = (1 << targetLen) - 1;
            int* dp = (int*)malloc((1 << targetLen) * sizeof(int));
            for (int i = 0; i < (1 << targetLen); i++) {
                dp[i] = INT_MAX;
            }
            dp[0] = 0;

            for (int state = 0; state < (1 << targetLen); state++) {
                if (dp[state] == INT_MAX) continue;
                for (int i = 0; i < stickersSize; i++) {
                    int nextState = state;
                    int stickerLen = strlen(stickers[i]);
                    for (int j = 0; j < stickerLen; j++) {
                        for (int k = 0; k < targetLen; k++) {
                            if (target[k] == stickers[i][j] && !(nextState & (1 << k))) {
                                nextState |= (1 << k);
                                break;
                            }
                        }
                    }
                    dp[nextState] = dp[nextState] < dp[state] + 1 ? dp[nextState] : dp[state] + 1;
                }
            }

            int result = dp[targetMask] == INT_MAX ? -1 : dp[targetMask];
            free(dp);
            return result;
        }

            
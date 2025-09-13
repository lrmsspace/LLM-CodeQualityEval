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
int minStickers(char** stickers, int stickersSize, char* target) {
    int targetSize = strlen(target);

    int* dp = (int*)malloc(sizeof(int) * (1 << targetSize));

    for (int i = 1; i < (1 << targetSize); i++) {
        dp[i] = -1;
    }

    dp[0] = 0;

    for (int i = 0; i < (1 << targetSize); i++) {
        if (dp[i] == -1) continue;

        for (int j = 0; j < stickersSize; j++) {
            int now = i;

            for (int k = 0; k < strlen(stickers[j]); k++) {
                for (int l = 0; l < targetSize; l++) {
                    if (stickers[j][k] == target[l] && ((now >> l) & 1) == 0) {
                        now |= 1 << l;
                        break;
                    }
                }
            }

            if (dp[now] == -1 || dp[now] > dp[i] + 1) {
                dp[now] = dp[i] + 1;
            }
        }
    }

    return dp[(1 << targetSize) - 1];
    
}
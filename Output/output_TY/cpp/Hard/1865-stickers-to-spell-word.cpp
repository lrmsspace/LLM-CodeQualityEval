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
        int m = target.size();
        vector<vector<int>> dp(1 << m, vector<int>(m, 0));
        vector<int> mask(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (stickers[i][j] == target[j]) {
                    mask[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (mask[i] == 0) {
                dp[1 << i][i] = 1;
            }
       }
       for (int i = 0; i < (1 << m); i++) {
           for (int j = 0; j < m; j++) {
               if (dp[i][j] > 0) {
                   for (int k = 0; k < n; k++) {
                       int mask2 = 0;
                       for (int l = 0; l < m; l++) {
                           if (stickers[k][l] == target[l] && ((i >> l) & 1) == 0) {
                               mask2 |= (1 << l);
                           }
                       }
                       if (dp[i ^ mask2][j] == 0) {
                           dp[i ^ mask2][j] = dp[i][j] + 1;
                       }
                   }
               }
           }
       }
       int ans = INT_MAX;
       for (int i = 0; i < (1 << m); i++) {
           ans = min(ans, dp[i][0]);
       }
       return ans == INT_MAX ? -1 : ans;
    }
};
/**https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/ */
//You are given a 2D integer array tiles where tiles[i] = [li, ri] represents that every tile j in the range li <= j <= ri is colored white.
//You are also given an integer carpetLen, the length of a single carpet that can be placed anywhere.
//Return the maximum number of white tiles that can be covered by the carpet.
// 
//Example 1:
//Input: tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
//Output: 9
//Explanation: Place the carpet starting on tile 10. 
//It covers 9 white tiles, so we return 9.
//Note that there may be other places where the carpet covers 9 white tiles.
//It can be shown that the carpet cannot cover more than 9 white tiles.
//Example 2:
//Input: tiles = [[10,11],[1,1]], carpetLen = 2
//Output: 2
//Explanation: Place the carpet starting on tile 10. 
//It covers 2 white tiles, so we return 2.
// 
//Constraints:
//	1 <= tiles.length <= 5 * 104
//	tiles[i].length == 2
//	1 <= li <= ri <= 109
//	1 <= carpetLen <= 109
//	The tiles are non-overlapping.
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        vector<int> dp(n, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int l = tiles[i][0], r = tiles[i][1];
            int len = r - l + 1;
            if (len < carpetLen) {
                dp[i] = len;
            } else {
                dp[i] = carpetLen;
            }
            res = max(res, dp[i]);
        }
        for (int i = 0; i < n; i++) {
            int l = tiles[i][0], r = tiles[i][1];
            int len = r - l + 1;
            if (len < carpetLen) {
                int left = carpetLen - len;
                int leftIdx = i - 1;
                while (left > 0 && leftIdx >= 0) {
                    int leftL = tiles[leftIdx][0], leftR = tiles[leftIdx][1];
                    int leftLen = leftR - leftL + 1;
                    if (leftLen < left) {
                        dp[i] += leftLen;
                        left -= leftLen;
                        leftIdx--;
                    } else {
                        dp[i] += left;
                        left = 0;
                    }
                }
                res = max(res, dp[i]);
            }
        }
        return res        
    }
};
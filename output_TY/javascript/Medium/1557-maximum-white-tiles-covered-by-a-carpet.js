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
/**
 * @param {number[][]} tiles
 * @param {number} carpetLen
 * @return {number}
 */
var maximumWhiteTiles = function(tiles, carpetLen) {
    let ans = 0, n = tiles.length, i = 0, tilesCovered = 0, j = 0, tilesCoveredLen = 0, tilesCoveredStart = 0;
    while (j < n) {
        if (tilesCoveredLen + tiles[j][1] - tiles[j][0] + 1 <= carpetLen) {
            tilesCoveredLen += tiles[j][1] - tiles[j][0] + 1;
            tilesCovered += tiles[j][1] - tiles[j][0] + 1;
            j++;
        } else {
            ans = Math.max(ans, tilesCovered + (carpetLen - tilesCoveredLen));
            while (i < n && tiles[i][1] < tiles[j][0] - 1) {
                tilesCovered -= tiles[i][1] - tiles[i][0] + 1;
            }
        }
    }
    return Math.max(ans, tilesCovered);
};
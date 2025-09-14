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
    public int maximumWhiteTiles(int[][] tiles, int carpetLen) {
        Arrays.sort(tiles, (a, b) -> Integer.compare(a[0], b[0]));
        int n = tiles.length;
        int[] prefix = new int[n];
        for (int i = 0; i < n; i++) {
            int end = tiles[i][1];
            int start = tiles[i][0];
            prefix[i] = (i > 0 ? prefix[i - 1] : 0) + (end - start + 1);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int end = tiles[i][1];
            int start = tiles[i][0];
            int endPos = start + carpetLen - 1;
            int r = Arrays.binarySearch(tiles, i, n, new int[]{endPos, 0});
            if (r < 0) {
                r = -r - 1;
            }
            int cover = prefix[r - 1] - (i > 0 ? prefix[i - 1] : 0);
            if (r < n && endPos >= tiles[r][0]) {
                cover += endPos - tiles[r][0] + 1;
            }
            ans = Math.max(ans, cover);
        }
        return ans;
    }
}
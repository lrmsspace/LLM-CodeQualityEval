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
        int n = tiles.length;
        Arrays.sort(tiles, (a, b) -> a[0] - b[0]);
        int[] right = new int[n];
        int rightMost = 0;
        for (int i = n - 1; i >= 0; i--) {
            right[i] = rightMost;
            rightMost = Math.max(rightMost, tiles[i][1]);
        }

        int ans = 0;
        int left = 0;
        int right = 0;
        int tilesCovered = 0;
        while (right < n) {
            if (tiles[right][0] - tiles[left] + tilesCovered <= carpetLen) {
                ans = Math.max(ans, tiles[right][1] - tiles[left] +1);
            }
        }
        while (right < n) {
            if (tiles[right][0] - tiles[left] + tilesCovered > carpetLen) {
                break;
            }
            tilesCovered += rightMost - tiles[right][1] + 1;
            right++;
            ans = Math.max(ans, tilesCovered + right - left);
        }
        while (left < n && right < n) {
            if (tiles[right][0] - tiles[left] + tilesCovered > carpetLen) {
                tilesCovered -= rightMost - tiles[left] + 1;
                left++;
            } else {
                right++;
                tilesCovered += rightMost - tiles[right] + 1;
                ans = Math.max(ans, tilesCovered + right - left);
            }
        }
        return ans;

    }
}
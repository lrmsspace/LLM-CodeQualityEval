/**https://leetcode.com/problems/rectangle-area-ii/ */
//You are given a 2D array of axis-aligned rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] denotes the ith rectangle where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner.
//Calculate the total area covered by all rectangles in the plane. Any area covered by two or more rectangles should only be counted once.
//Return the total area. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
//Output: 6
//Explanation: A total area of 6 is covered by all three rectangles, as illustrated in the picture.
//From (1,1) to (2,2), the green and red rectangles overlap.
//From (1,0) to (2,3), all three rectangles overlap.
//Example 2:
//Input: rectangles = [[0,0,1000000000,1000000000]]
//Output: 49
//Explanation: The answer is 1018 modulo (109 + 7), which is 49.
// 
//Constraints:
//	1 <= rectangles.length <= 200
//	rectanges[i].length == 4
//	0 <= xi1, yi1, xi2, yi2 <= 109
//	xi1 <= xi2
//	yi1 <= yi2
class Solution {
    public int rectangleArea(int[][] rectangles) {
        int n = rectangles.length;
        int[][] points = new int[n * 4][2];
        
        for (int i = 0; i < n; ++i) {
            int[] r = rectangles[i];
            points[i * 4] = new int[]{r[0], r[1]};
            points[i * 4 + 1] = new int[]{r[0], r[3]};
            points[i * 4 + 2] = new int[]{r[2], r[1]};
            points[i * 4 + 3] = new int[]{r[2], r[3]};
        }
        
        Arrays.sort(points, (a, b) -> a[0] - b[0]);
        
        int ans = 0;
        int j = 0;
        
        for (int i = 0; i < points.length; ++i) {
            while (j < points.length && points[j][0] <= points[i][0]) {
                ans = (ans + (points[j][1] - points[i][1]) % (int)(1e9 + 7)) % (int)(1e9 + 7);
                ++j;
            }
        }
        
        return ans;
        
    }
}
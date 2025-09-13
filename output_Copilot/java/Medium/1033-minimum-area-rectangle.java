/**https://leetcode.com/problems/minimum-area-rectangle/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.
// 
//Example 1:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
//Output: 4
//Example 2:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
//Output: 2
// 
//Constraints:
//	1 <= points.length <= 500
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
class Solution {
    public int minAreaRect(int[][] points) {
           Set<String> set = new HashSet<>();
            for (int[] point : points) {
                set.add(point[0] + "," + point[1]);
            }
            int minArea = Integer.MAX_VALUE;
            for (int i = 0; i < points.length; i++) {
                for (int j = i + 1; j < points.length; j++) {
                    if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                        String p1 = points[i][0] + "," + points[j][1];
                        String p2 = points[j][0] + "," + points[i][1];
                        if (set.contains(p1) && set.contains(p2)) {
                            int area = Math.abs(points[i][0] - points[j][0]) * Math.abs(points[i][1] - points[j][1]);
                            minArea = Math.min(minArea, area);
                        }
                    }
                }
            }
            return minArea == Integer.MAX_VALUE ? 0 : minArea;     
    }
}
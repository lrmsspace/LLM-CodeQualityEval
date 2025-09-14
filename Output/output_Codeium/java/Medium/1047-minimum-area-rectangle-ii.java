/**https://leetcode.com/problems/minimum-area-rectangle-ii/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.
//Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: points = [[1,2],[2,1],[1,0],[0,1]]
//Output: 2.00000
//Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
//Example 2:
//Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
//Output: 1.00000
//Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
//Example 3:
//Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
//Output: 0
//Explanation: There is no possible rectangle to form from these points.
// 
//Constraints:
//	1 <= points.length <= 50
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
class Solution {
    public double minAreaFreeRect(int[][] points) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int[] p : points) {
            map.computeIfAbsent(p[0], k -> new HashSet<>()).add(p[1]);
        }
        double res = Double.MAX_VALUE;
        for (int i = 0; i < points.length; i++) {
            for (int j = i + 1; j < points.length; j++) {
                for (int k = j + 1; k < points.length; k++) {
                    if (map.get(points[i][0]).contains(points[j][1]) && map.get(points[j][0]).contains(points[k][1])
                            && map.get(points[k][0]).contains(points[i][1])) {
                        double a = Math.sqrt(Math.pow(points[j][0] - points[i][0], 2) + Math.pow(points[k][1] - points[i][1], 2));
                        double b = Math.sqrt(Math.pow(points[k][0] - points[j][0], 2) + Math.pow(points[i][1] - points[j][1], 2));
                        res = Math.min(res, a * b);
                    }
                }
            }
        }
        return res == Double.MAX_VALUE ? 0 : res;
    }
}
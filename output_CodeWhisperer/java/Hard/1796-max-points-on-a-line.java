/**https://leetcode.com/problems/max-points-on-a-line/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
// 
//Example 1:
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 3
//Example 2:
//Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//Output: 4
// 
//Constraints:
//	1 <= points.length <= 300
//	points[i].length == 2
//	-104 <= xi, yi <= 104
//	All the points are unique.
import java.util.Map;
import java.util.HashMap;
class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        if (n <= 2) return n;
        int max = 0;
        for (int i = 0; i < n; i++) {
            Map<Double, Integer> map = new HashMap<>();
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    double slope = 0;
                    if (points[j][0] == points[i][0]) slope = Double.POSITIVE_INFINITY;
                    else slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                    map.put(slope, map.getOrDefault(slope, 0) + 1);
                }
            }
            for (int count : map.values()) {
                max = Math.max(max, count + 1);
            }
        }
        return max;       
    }
}
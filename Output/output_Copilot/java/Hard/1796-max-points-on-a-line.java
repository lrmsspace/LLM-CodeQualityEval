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
class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        if (n < 3) return n; // If there are less than 3 points, all of them are on the same line.

        int maxPoints = 0;
        for (int i = 0; i < n; i++) {
            Map<Double, Integer> slopeCount = new HashMap<>();
            for (int j = i + 1; j < n; j++) {
                double slope = calculateSlope(points[i], points[j]);
                slopeCount.put(slope, slopeCount.getOrDefault(slope, 0) + 1);
            }
            maxPoints = Math.max(maxPoints, Collections.max(slopeCount.values(), Integer::compareTo) + 1); // +1 to include the point itself
        }
        return maxPoints;        
    }
}
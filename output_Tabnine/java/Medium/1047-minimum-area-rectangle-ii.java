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
        Map<Integer, Map<Integer, Integer>> map = new HashMap<>();
        for (int[] point : points) {
            map.computeIfAbsent(point[0], k -> new HashMap<>()).put(point[1], map.getOrDefault(point[0], new HashMap<>()).getOrDefault(point[1], 0) + 1);
        }
        
        int n = points.length;
        double minArea = Double.MAX_VALUE;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                
                if (dx == dy && dx!= 0) {
                    int x = (points[i][0] + points[j][0]) / 2;
                    int y = (points[i][1] + points[j][1]) / 2;
                    
                    if (map.get(x).getOrDefault(y - dy, 0) > 0 && map.get(x).getOrDefault(y + dy, 0) > 0) {
                        minArea = Math.min(minArea, dx * dy);
                    }
                }
            }
            
            for (Map.Entry<Integer, Map<Integer, Integer>> entry : map.entrySet()) {
                entry.getValue().clear();
            }

            map.get(points[i][0]).put(points[i][1], map.get(points[i][0]).getOrDefault(points[i][1], 0) - 1);
            map.get(points[j][0]).put(points[j][1], map.get(points[j][0]).getOrDefault(points[j][1], 0) - 1);
        }
        
        return minArea == Double.MAX_VALUE? 0 : minArea;
        
    }
}
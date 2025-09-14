/**https://leetcode.com/problems/perfect-rectangle/ */
//Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).
//Return true if all the rectangles together form an exact cover of a rectangular region.
// 
//Example 1:
//Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
//Output: true
//Explanation: All 5 rectangles together form an exact cover of a rectangular region.
//Example 2:
//Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
//Output: false
//Explanation: Because there is a gap between the two rectangular regions.
//Example 3:
//Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
//Output: false
//Explanation: Because two of the rectangles overlap with each other.
// 
//Constraints:
//	1 <= rectangles.length <= 2 * 104
//	rectangles[i].length == 4
//	-105 <= xi < ai <= 105
//	-105 <= yi < bi <= 105
class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        int minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE;
        int maxX = Integer.MIN_VALUE, maxY = Integer.MIN_VALUE;
        int area = 0;
        
        for (int[] rectangle : rectangles) {
            minX = Math.min(minX, rectangle[0]);
            minY = Math.min(minY, rectangle[1]);
            maxX = Math.max(maxX, rectangle[2]);
            maxY = Math.max(maxY, rectangle[3]);
            area += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
        }
        
        int totalArea = (maxX - minX) * (maxY - minY);
        
        if (totalArea!= area) return false;
        
        Set<String> points = new HashSet<>();
        
        for (int[] rectangle : rectangles) {
            for (int x = rectangle[0]; x < rectangle[2]; x++) {
                for (int y = rectangle[1]; y < rectangle[3]; y++) {
                    points.add(x + "," + y);
                }
            }
        }
        
        return points.size() == totalArea;
        
    }
}
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
        // Step 1: Calculate the area of the rectangles and the corners
        int area = 0;
        HashSet<String> corners = new HashSet<>();
        int minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE, maxX = Integer.MIN_VALUE, maxY = Integer.MIN_VALUE;

        for (int[] rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            area += (x2 - x1) * (y2 - y1);
            minX = Math.min(minX, x1);
            minY = Math.min(minY, y1);
            maxX = Math.max(maxX, x2);
            maxY = Math.max(maxY, y2);

            // Add corners to the set
            addCorner(corners, x1, y1);
            addCorner(corners, x1, y2);
            addCorner(corners, x2, y1);
            addCorner(corners, x2, y2);
        }

        // Step 2: Check if the corners set has exactly 4 corners and they are the expected ones
        if (corners.size() != 4 || !corners.contains(minX + "," + minY) || !corners.contains(minX + "," + maxY) ||
                !corners.contains(maxX + "," + minY) || !corners.contains(maxX + "," + maxY)) {
            return false;
        }

        // Step 3: Check if the total area matches the area of the bounding rectangle
        return area == (maxX - minX) * (maxY - minY);        
    }
}
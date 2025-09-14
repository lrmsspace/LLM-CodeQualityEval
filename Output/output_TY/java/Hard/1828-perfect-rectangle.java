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
       
        HashMap<String, Integer> map = new HashMap<>();
        int area = 0;
        int x1 = Integer.MAX_VALUE;
        int y1 = Integer.MAX_VALUE;
        int x2 = Integer.MIN_VALUE;
        int y2 = Integer.MIN_VALUE;
        for (int[] rect : rectangles) {
            String leftTop = rect[0] + "," + rect[1];
            String rightBottom = rect[2] + "," + rect[3];
            map.put(leftTop, map.getOrDefault(leftTop, 0) + 1);
            map.put(rightBottom, map.getOrDefault(rightBottom, 0) + 1);
        }
        for (String key : map.keySet()) {
            String[] point = key.split(",");
            int x = Integer.parseInt(point[0]);
            int y = Integer.parseInt(point[1]);
            if (map.get(key) == 1) {
                y1 = Math.min(y1, y);
                x2 = Math.max(x2, x);
                y2 = Math.max(y2, y);
            }
        }
        return (x2 - x1) * (y2 - y1) <= k;
    }
}
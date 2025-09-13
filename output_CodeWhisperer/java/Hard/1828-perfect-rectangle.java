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
import java.util.HashSet;
class Solution {
    public boolean isRectangleCover(int[][] rectangles)
    {
        int x1 = Integer.MAX_VALUE, y1 = Integer.MAX_VALUE, x2 = Integer.MIN_VALUE, y2 = Integer.MIN_VALUE;
        int area = 0;
        HashSet<String> set = new HashSet<>();
        for (int[] rectangle : rectangles)
        {
            x1 = Math.min(x1, rectangle[0]);
            y1 = Math.min(y1, rectangle[1]);
            x2 = Math.max(x2, rectangle[2]);
            y2 = Math.max(y2, rectangle[3]);
            area += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
            String s1 = rectangle[0] + " " + rectangle[1];
            String s2 = rectangle[0] + " " + rectangle[3];
            String s3 = rectangle[2] + " " + rectangle[3];
            String s4 = rectangle[2] + " " + rectangle[1];
            if (!set.add(s1)) set.remove(s1);
            if (!set.add(s2)) set.remove(s2);
            if (!set.add(s3)) set.remove(s3);
            if (!set.add(s4)) set.remove(s4);
        }
        if (!set.contains(x1 + " " + y1) || !set.contains(x1 + " " + y2) || !set.contains(x2 + " " + y1) || !set.contains(x2 + " " + y2) || set.size() != 4)
            return false;
        return area == (x2 - x1) * (y2 - y1);   
    }
}
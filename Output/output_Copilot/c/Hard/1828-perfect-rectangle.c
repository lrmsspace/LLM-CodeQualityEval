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
bool isRectangleCover(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
       int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN, area = 0;
        unordered_set<string> points;
        for (int i = 0; i < rectanglesSize; i++) {
            x1 = fmin(x1, rectangles[i][0]);
            y1 = fmin(y1, rectangles[i][1]);
            x2 = fmax(x2, rectangles[i][2]);
            y2 = fmax(y2, rectangles[i][3]);
            area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
            string p1 = to_string(rectangles[i][0]) + "," + to_string(rectangles[i][1]);
            string p2 = to_string(rectangles[i][0]) + "," + to_string(rectangles[i][3]);
            string p3 = to_string(rectangles[i][2]) + "," + to_string(rectangles[i][3]);
            string p4 = to_string(rectangles[i][2]) + "," + to_string(rectangles[i][1]);
            if (!points.insert(p1).second) points.erase(p1);
            if (!points.insert(p2).second) points.erase(p2);
            if (!points.insert(p3).second) points.erase(p3);
            if (!points.insert(p4).second) points.erase(p4);
        }
        if (points.size() != 4 || !points.count(to_string(x1) + "," + to_string(y1)) || !points.count(to_string(x1) + "," + to_string(y2)) || !points.count(to_string(x2) + "," + to_string(y1)) || !points.count(to_string(x2) + "," + to_string(y2))) return false;
        return area == (x2 - x1) * (y2 - y1);     
}
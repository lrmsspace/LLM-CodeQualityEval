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
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int totalArea = 0;
        unordered_map<int, int> xCount, yCount;
        int xMin = INT_MAX, xMax = INT_MIN, yMin = INT_MAX, yMax = INT_MIN;
        for (const auto& rec : rectangles) {
            int x1 = rec[0], y1 = rec[1], x2 = rec[2], y2 = rec[3];
            totalArea += (x2 - x1) * (y2 - y1);
            xCount[x1]++; xCount[x2]++;
            yCount[y1]++; yCount[y2]++;
            xMin = min(xMin, x1); xMax = max(xMax, x2);
            yMin = min(yMin, y1); yMax = max(yMax, y2);
        }
        int area = (xMax - xMin) * (yMax - yMin);
        if (totalArea != area) return false;
        if (xCount[xMin] != 1 || xCount[xMax] != 1 || yCount[yMin] != 1 || yCount[yMax] != 1) return false;
        for (const auto& [x, cnt] : xCount) {
            if (cnt % 2 != 0 && x != xMin && x != xMax) return false;
        }
        for (const auto& [y, cnt] : yCount) {
            if (cnt % 2 != 0 && y != yMin && y != yMax) return false;
        }
        return true;
    }
};
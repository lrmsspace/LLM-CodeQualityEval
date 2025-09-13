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
    int left = INT_MAX, right = INT_MIN, top = INT_MIN, bottom = INT_MAX;
    int area = 0;
    int corners[4][2] = {{INT_MAX, INT_MAX}, {INT_MAX, INT_MIN}, {INT_MIN, INT_MAX}, {INT_MIN, INT_MIN}};
    bool corner[4] = {false, false, false, false};
    for (int i = 0; i < rectanglesSize; i++) {
        left = left < rectangles[i][0] ? left : rectangles[i][0];
        right = right > rectangles[i][2] ? right : rectangles[i][2];
        bottom = bottom < rectangles[i][1] ? bottom : rectangles[i][1];
        top = top > rectangles[i][3] ? top : rectangles[i][3];
        area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
        for (int j = 0; j < 4; j++) {
            if (rectangles[i][0] == corners[j][0] && rectangles[i][1] == corners[j][1]) {
                corner[j] = !corner[j];
            }
        }
    }
    if (area != (right - left) * (top - bottom)) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        if (!corner[i]) {
            return false;
        }
    }
    return true;
    
}
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
    int area = 0;
    int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
    int count[101][101] = {0};
    for (int i = 0; i < rectanglesSize; i++) {
        int x = rectangles[i][0], y = rectangles[i][1], a = rectangles[i][2], b = rectangles[i][3];
        if (count[x][y] == 1 || count[x][b] == 1 || count[a][y] == 1 || count[a][b] == 1) return false;
        if (count[x][y] == 0) x1 = min(x1, x), y1 = min(y1, y);
        if (count[a][b] == 0) x2 = max(x2, a), y2 = max(y2, b);
        count[x][y]++, count[x][b]++, count[a][y]++, count[a][b]++;
        area += (a - x) * (b - y);
    }
    return area == (x2 - x1) * (y2 - y1);
}

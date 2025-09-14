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
    int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
    int area = 0;
    int count = 0;
    
    for (int i = 0; i < rectanglesSize; i++) {
        minX = fmin(minX, rectangles[i][0]);
        minY = fmin(minY, rectangles[i][1]);
        maxX = fmax(maxX, rectangles[i][2]);
        maxY = fmax(maxY, rectangles[i][3]);
        area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
        count += 4;
    }
    
    int totalArea = (maxX - minX) * (maxY - minY);
    if (area!= totalArea || count!= 4 * rectanglesSize) {
        return false;
    }
    
    int* points = (int*)calloc(count, sizeof(int));
    int pointCount = 0;
    
    for (int i = 0; i < rectanglesSize; i++) {
        points[pointCount++] = rectangles[i][0];
        points[pointCount++] = rectangles[i][1];
        points[pointCount++] = rectangles[i][2];
        points[pointCount++] = rectangles[i][3];
    }
    
    qsort(points, count, sizeof(int), compare);
    
    for (int i = 0; i < count - 1; i++) {
        if (points[i] == points[i + 1]) {
            return false;
        }
    }
    
    int x = minX, y = minY;
    for (int i = 0; i < count; i += 2) {
        if (points[i]!= x) {
            return false;
        }
        x = points[i + 1];
    }
    
    for (int i = 0; i < count; i += 2) {
        if (points[i]!= y) {
            return false;
        }
        y = points[i + 1];
    }
    
    free(points);
    return true;
    
}
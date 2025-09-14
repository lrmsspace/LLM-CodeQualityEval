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
//	-105 <= xi, yi, ai, bi <= 105
bool isRectangleCover(int** rectangles, int rectanglesSize, int* rectanglesColSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, j1, k1, l1, m1, n1, o1, p1, q1, r1, s1, t1, u1, v1, w1, x1, y1, z1,a1, b1, c1, d1, e1, f  ;
    for (i = 0; i < rectanglesSize; i++) {
        for (j = i + 1; j < rectanglesSize; j++) {
            if (rectangles[i][0] == rectangles[j][0] && rectangles[i][1] == rectangles[j][1] && rectangles[i][2] == rectangles[j][2] && rectangles[i][3] == rectangles[j][3]) {
                rectangles[j][0] = rectangles[j][1]= rectangles[j][2] = rectangles[j][3] = -1;
            }
        }
    }
    for (i = 0; i < rectanglesSize; i++) {
        if (rectangles[i][0] != -1) {
            return false;
        }
    }
    return true;
}
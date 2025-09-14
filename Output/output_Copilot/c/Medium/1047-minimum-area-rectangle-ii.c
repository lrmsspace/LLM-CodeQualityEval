/**https://leetcode.com/problems/minimum-area-rectangle-ii/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.
//Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: points = [[1,2],[2,1],[1,0],[0,1]]
//Output: 2.00000
//Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
//Example 2:
//Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
//Output: 1.00000
//Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
//Example 3:
//Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
//Output: 0
//Explanation: There is no possible rectangle to form from these points.
// 
//Constraints:
//	1 <= points.length <= 50
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
double minAreaFreeRect(int** points, int pointsSize, int* pointsColSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[40001] = {0};
    int b[40001] = {0};
    int c[40001] = {0};
    int d[40001] = {0};
    int e[40001] = {0};
    int f[40001] = {0};
    int g[40001] = {0};
    int h[40001] = {0};
    double ans = 0;
    for(i = 0; i < pointsSize; i++) {
        a[points[i][0] * 200 + points[i][1]] = 1;
    }
    for(i = 0; i < pointsSize; i++) {
        for(j = i + 1; j < pointsSize; j++) {
            for(k = j + 1; k < pointsSize; k++) {
                if(points[i][0] != points[j][0] && points[i][1] != points[j][1] && points[i][0] != points[k][0] && points[i][1] != points[k][1] && points[j][0] != points[k][0] && points[j][1] != points[k][1]) {
                    if(a[points[i][0] * 200 + points[j][1]] == 1 && a[points[j][0] * 200 + points[i][1]] == 1 && a[points[i][0] * 200 + points[k][1]] == 1 && a[points[k][0] * 200 + points[i][1]] == 1 && a[points[j][0] * 200 + points[k][1]] == 1 && a[points[k][0] * 200 + points[j][1]] == 1) {
                        if(ans == 0) {
                            ans = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2)) * sqrt(pow(points[i][0] - points[k][0], 2) + pow(points[i][1] - points[k][1], 2));
                        } else {
                            ans
                            = min(ans, sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2)) * sqrt(pow(points[i][0] - points[k][0], 2) + pow(points[i][1] - points[k][1], 2)));

                            }
                        }
                    }
                }
            }
            }

    return ans;
}
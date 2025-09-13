/**https://leetcode.com/problems/minimum-area-rectangle/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.
// 
//Example 1:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
//Output: 4
//Example 2:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
//Output: 2
// 
//Constraints:
//	1 <= points.length <= 500
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
int minAreaRect(int** points, int pointsSize, int* pointsColSize) {
       int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
        int a[40001] = {0};
        int b[40001] = {0};
        int c[40001] = {0};
        int d[40001] = {0};
        int e[40001] = {0};
        int f[40001] = {0};
        int g[40001] = {0};
        int h[40001] = {0};
        int ans = 0;
        for(i = 0; i < pointsSize; i++) {
            a[points[i][0] * 200 + points[i][1]] = 1;
        }
        for(i = 0; i < pointsSize; i++) {
            for(j = i + 1; j < pointsSize; j++) {
                if(points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                    if(a[points[i][0] * 200 + points[j][1]] == 1 && a[points[j][0] * 200 + points[i][1]] == 1) {
                        if(ans == 0) {
                            ans = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]);
                        } else {
                            ans = min(ans, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
                        }
                    }
                }
            }
        }
        return ans;     
}
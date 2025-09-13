/**https://leetcode.com/problems/max-points-on-a-line/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
// 
//Example 1:
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 3
//Example 2:
//Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//Output: 4
// 
//Constraints:
//	1 <= points.length <= 300
//	points[i].length == 2
//	-104 <= xi, yi <= 104
//	All the points are unique.
int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    int max = 0;
    for (int i = 0; i < pointsSize; i++) {
        int same = 1;
        int hash[360*2] = {0}; // 360 * 2: 0 ~ 359 for slope, -360 ~ -1 for vertical line
        for (int j = i + 1; j < pointsSize; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            if (dx == 0 && dy == 0) {
                same++;
                continue;
            }
            int gcd = gcd(dx, dy);
            dx /= gcd;
            dy /= gcd;
            int idx = (dy > 0) ? (dx + 360) : (dx + 360 - 1);
            hash[idx]++;
            max = fmax(max, hash[idx] + same);
        }
    }
    return max;
}
/**https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/ */
//Alice is throwing n darts on a very large wall. You are given an array darts where darts[i] = [xi, yi] is the position of the ith dart that Alice threw on the wall.
//Bob knows the positions of the n darts on the wall. He wants to place a dartboard of radius r on the wall so that the maximum number of darts that Alice throws lie on the dartboard.
//Given the integer r, return the maximum number of darts that can lie on the dartboard.
// 
//Example 1:
//Input: darts = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
//Output: 4
//Explanation: Circle dartboard with center in (0,0) and radius = 2 contain all points.
//Example 2:
//Input: darts = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
//Output: 5
//Explanation: Circle dartboard with center in (0,4) and radius = 5 contain all points except the point (7,8).
// 
//Constraints:
//	1 <= darts.length <= 100
//	darts[i].length == 2
//	-104 <= xi, yi <= 104
//	All the darts are unique
//	1 <= r <= 5000
class Solution {
public:
    int numPoints(vector<vector<int>>& darts, int r) {
        int n = darts.size();
        int res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double x1 = darts[i][0], y1 = darts[i][1];
                double x2 = darts[j][0], y2 = darts[j][1];
                double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
                if (d > 2 * r) {
                    continue;
                }
                double x0 = (x1 + x2) / 2, y0 = (y1 + y2) / 2;
                double theta = atan2(y2 - y1, x2 - x1);
                double d0 = sqrt(r * r - d * d / 4);
                double x3 = x0 + d0 * sin(theta), y3 = y0 - d0 * cos(theta);
                double x4 = x0 - d0 * sin(theta), y4 = y0 + d0 * cos(theta);
                int cnt1 = 0, cnt2 = 0;
                for (int k = 0; k < n; k++) {
                    double x = darts[k][0], y = darts[k][1];
                    if (sqrt(pow(x - x3, 2) + pow(y - y3, 2)) <= r) {
                        cnt1++;
                    }
                    if (sqrt(pow(x - x4, 2) + pow(y - y4, 2)) <= r) {
                        cnt2++;
                    }
                }
                res = max({res, cnt1, cnt2});
            }
        }
        return res;
    }
};
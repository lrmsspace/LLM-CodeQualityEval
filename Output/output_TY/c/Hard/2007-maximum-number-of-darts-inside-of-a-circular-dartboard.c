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
int numPoints(int** darts, int dartsSize, int* dartsColSize, int r){
    int ans = 0;
    for (int i = 0; i < dartsSize; i++) {
        int x = darts[i][0], y = darts[i][1];
        int d = r * r - y * y;
        int x1 = x - sqrt(max(0, d)), x2 = x + sqrt(max(0, d));
        for (int j = -1; j <= 1; j += 2) {
           for (int k = -1; k <= 1; k += 2) {
               int cnt = 0;
               for (int l = 0; l < dartsSize; l++) {
                   if (l == i) continue;
                   int xx = darts[l][0], yy = darts[l][1];
                   if (xx * xx + yy * yy <= r * r) cnt++;
               }
               ans = max(ans, cnt);
            }
        }
    }
    return ans;
}
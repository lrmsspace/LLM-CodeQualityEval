/**https://leetcode.com/problems/number-of-boomerangs/ */
//You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
//Return the number of boomerangs.
// 
//Example 1:
//Input: points = [[0,0],[1,0],[2,0]]
//Output: 2
//Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
//Example 2:
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 2
//Example 3:
//Input: points = [[1,1]]
//Output: 0
// 
//Constraints:
//	n == points.length
//	1 <= n <= 500
//	points[i].length == 2
//	-104 <= xi, yi <= 104
//	All the points are unique.
int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize){
    int i, j, k, ans = 0;
    for (i = 0; i < pointsSize; i++) {
        int d[10001] = {0};
        for (j = 0; j < pointsSize; j++) {
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            int d2 = dx * dx + dy * dy;
            d[d2]++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        int d[10001] = {0};
        for (j = 0; j < pointsSize; j++) {
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            int d2 = dx * dx + dy * dy;
            ans += d[d2] * 2;
        }
    }
    return ans;
}
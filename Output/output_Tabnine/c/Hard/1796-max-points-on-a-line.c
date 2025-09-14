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
    int n = pointsSize;
    if (n <= 2) return n;
    
    int maxCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int samePointCount = 1;
        int sameLineCount = 0;
        int verticalCount = 0;
        
        int x1 = points[i][0], y1 = points[i][1];
        for (int j = i + 1; j < n; j++) {
            int x2 = points[j][0], y2 = points[j][1];
            
            if (x1 == x2 && y1 == y2) {
                samePointCount++;
                continue;
            }
            
            if (x1 == x2) {
                verticalCount++;
                continue;
            }
            
            double slope = (double)(y2 - y1) / (x2 - x1);
            int count = 2;
            for (int k = j + 1; k < n; k++) {
                int x3 = points[k][0], y3 = points[k][1];
                if (slope == (double)(y3 - y1) / (x3 - x1)) {
                    count++;
                }
            }
            
            sameLineCount = fmax(sameLineCount, count);


    }
        
        maxCount = fmax(maxCount, samePointCount + sameLineCount + verticalCount);
    }
    
    return maxCount;
    
}
/**https://leetcode.com/problems/check-if-it-is-a-straight-line/ */
//You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
// 
// 
//Example 1:
//Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
//Output: true
//Example 2:
//Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
//Output: false
// 
//Constraints:
//	2 <= coordinates.length <= 1000
//	coordinates[i].length == 2
//	-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
//	coordinates contains no duplicate point.
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int n = coordinates.length;
        if (n < 3) return true;
        
        double slope = (double)(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        
        for (int i = 2; i < n; i++) {
            if (slope!= (double)(coordinates[i][1] - coordinates[0][1]) / (coordinates[i][0] - coordinates[0][0])) {
                return false;
            }
        }
        
        return true;
        
    }
}
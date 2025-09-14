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
    public int numPoints(int[][] darts, int r) {
        int n = darts.length;
        int maxDarts = 1; // At least one dart can be inside the dartboard

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double distance = Math.sqrt(Math.pow(darts[i][0] - darts[j][0], 2) + Math.pow(darts[i][1] - darts[j][1], 2));
                if (distance > 2 * r) continue; // Skip if the distance is greater than the diameter of the dartboard

                double midX = (darts[i][0] + darts[j][0]) / 2.0;
                double midY = (darts[i][1] + darts[j][1]) / 2.0;
                double h = Math.sqrt(r * r - (distance / 2) * (distance / 2));

                double dx = (darts[j][1] - darts[i][1]) * h / distance;
                double dy = (darts[i][0] - darts[j][0]) * h / distance;

                double centerX1 = midX + dx;
                double centerY1 = midY - dy;
                double centerX2 = midX - dx;
                double centerY2 = midY + dy;

                maxDarts = Math.max(maxDarts, countDarts(darts, centerX1, centerY1, r));
                maxDarts = Math.max(maxDarts, countDarts(darts, centerX2, centerY2, r));
            }
        }

        return maxDarts;        
    }
}
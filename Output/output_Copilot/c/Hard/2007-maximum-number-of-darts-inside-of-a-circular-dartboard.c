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


    int countPointsInsideCircle(int** darts, int dartsSize, double cx, double cy, int r) {
        int count = 0;
        for (int i = 0; i < dartsSize; i++) {
            double dx = darts[i][0] - cx;
            double dy = darts[i][1] - cy;
            if (dx * dx + dy * dy <= r * r) {
                count++;
            }
        }
        return count;
    }

    int numPoints(int** darts, int dartsSize, int* dartsColSize, int r) {
        int maxPoints = 1;
        for (int i = 0; i < dartsSize; i++) {
            for (int j = i + 1; j < dartsSize; j++) {
                double dx = darts[j][0] - darts[i][0];
                double dy = darts[j][1] - darts[i][1];
                double dist = sqrt(dx * dx + dy * dy);
                if (dist > 2 * r) {
                    continue;
                }
                double midX = (darts[i][0] + darts[j][0]) / 2.0;
                double midY = (darts[i][1] + darts[j][1]) / 2.0;
                double offset = sqrt(r * r - (dist / 2.0) * (dist / 2.0));
                double normX = -dy / dist;
                double normY = dx / dist;

                double cx1 = midX + offset * normX;
                double cy1 = midY + offset * normY;
                double cx2 = midX - offset * normX;
                double cy2 = midY - offset * normY;

                maxPoints = fmax(maxPoints, countPointsInsideCircle(darts, dartsSize, cx1, cy1, r));
                maxPoints = fmax(maxPoints, countPointsInsideCircle(darts, dartsSize, cx2, cy2, r));
            }
        }
        return maxPoints;
    }

        
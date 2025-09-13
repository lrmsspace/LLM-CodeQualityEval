/*
 You are given an array points representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].
 The distance between two points is defined as their Manhattan distance.
 Return the minimum possible value for maximum distance between any two points by removing exactly one point.
 Example 1:
 Input: points = [[3,10],[5,15],[10,2],[4,4]]
 Output: 12
 Explanation:
 The maximum distance after removing each point is the following:
 After removing the 0th point the maximum distance is between points (5, 15) and (10, 2), which is |5 - 10| + |15 - 2| = 18.
 After removing the 1st point the maximum distance is between points (3, 10) and (10, 2), which is |3 - 10| + |10 - 2| = 15.
 After removing the 2nd point the maximum distance is between points (5, 15) and (4, 4), which is |5 - 4| + |15 - 4| = 12.
 After removing the 3rd point the maximum distance is between points (5, 15) and (10, 2), which is |5 - 10| + |15 - 2| = 18.
 12 is the minimum possible maximum distance between any two points after removing exactly one point.
 Example 2:
 Input: points = [[1,1],[1,1],[1,1]]
 Output: 0
 Explanation:
 Removing any of the points results in the maximum distance between any two points of 0.
 Constraints:
 3 <= points.length <= 105
 points[i].length == 2
 1 <= points[i][0], points[i][1] <= 108
*/

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 3) return 0; // If there are 3 or fewer points, removing one will always result in a distance of 0.

        int minX = INT_MAX, maxX = INT_MIN;
        int minY = INT_MAX, maxY = INT_MIN;

        for (const auto& point : points) {
            minX = min(minX, point[0]);
            maxX = max(maxX, point[0]);
            minY = min(minY, point[1]);
            maxY = max(maxY, point[1]);
        }

        // Calculate the maximum distance without removing any points
        int maxDistanceWithoutRemoval = (maxX - minX) + (maxY - minY);

        // Check the maximum distance after removing each point
        int minMaxDistanceAfterRemoval = INT_MAX;

        for (const auto& point : points) {
            int x = point[0], y = point[1];
            int newMinX = (x == minX) ? INT_MAX : minX;
            int newMaxX = (x == maxX) ? INT_MIN : maxX;
            int newMinY = (y == minY) ? INT_MAX : minY;
            int newMaxY = (y == maxY) ? INT_MIN : maxY;

            for (const auto& p : points) {
                if (p != point) {
                    newMinX = min(newMinX, p[0]);
                    newMaxX = max(newMaxX, p[0]);
                    newMinY = min(newMinY, p[1]);
                    newMaxY = max(newMaxY, p[1]);
                }
            }

            int currentMaxDistanceAfterRemoval = (newMaxX - newMinX) + (newMaxY - newMinY);
            minMaxDistanceAfterRemoval = min(minMaxDistanceAfterRemoval, currentMaxDistanceAfterRemoval);
        }

        return minMaxDistanceAfterRemoval;  
        
    }
};
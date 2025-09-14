/*
 You are given a 2D array coords of size n x 2, representing the coordinates of n points in an infinite Cartesian plane.
 Find twice the maximum area of a triangle with its corners at any three elements from coords, such that at least one side of this triangle is parallel to the x-axis or y-axis. Formally, if the maximum area of such a triangle is A, return 2 * A.
 If no such triangle exists, return -1.
 Note that a triangle cannot have zero area.
 Example 1:
 Input: coords = [[1,1],[1,2],[3,2],[3,3]]
 Output: 2
 Explanation:
 The triangle shown in the image has a base 1 and height 2. Hence its area is 1/2 * base * height = 1.
 Example 2:
 Input: coords = [[1,1],[2,2],[3,3]]
 Output: -1
 Explanation:
 The only possible triangle has corners (1, 1), (2, 2), and (3, 3). None of its sides are parallel to the x-axis or the y-axis.
 Constraints:
 1 <= n == coords.length <= 105
 1 <= coords[i][0], coords[i][1] <= 106
 All coords[i] are unique.
*/

class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        int n = coords.size();
        long long maxArea = -1;

        // Check all combinations of three points
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    // Get the coordinates of the points
                    int x1 = coords[i][0], y1 = coords[i][1];
                    int x2 = coords[j][0], y2 = coords[j][1];
                    int x3 = coords[k][0], y3 = coords[k][1];

                    // Check if at least one side is parallel to the axes
                    if (x1 == x2 || x2 == x3 || x1 == x3 || y1 == y2 || y2 == y3 || y1 == y3) {
                        // Calculate the area using the determinant method
                        long long area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))) / 2);
                        maxArea = max(maxArea, area);
                    }
                }
            }
        }

        return maxArea;
    }
};
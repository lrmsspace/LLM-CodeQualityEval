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
long long maxArea(int** coords, int coordsSize, int* coordsColSize) {
    long long maxArea = -1;

    for (int i = 0; i < coordsSize; i++) {
        for (int j = i + 1; j < coordsSize; j++) {
            for (int k = j + 1; k < coordsSize; k++) {
                int x1 = coords[i][0];
                int y1 = coords[i][1];
                int x2 = coords[j][0];
                int y2 = coords[j][1];
                int x3 = coords[k][0];
                int y3 = coords[k][1];

                // Check if at least one side is parallel to the x-axis or y-axis
                if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)) {
                    // Calculate the area of the triangle
                    long long base = abs(x2 - x1);
                    long long height = abs(y2 - y1);
                    long long area = (base * height) / 2;

                    // Update the maximum area if necessary
                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
            }
        }
    }

    return 2 * maxArea;
}
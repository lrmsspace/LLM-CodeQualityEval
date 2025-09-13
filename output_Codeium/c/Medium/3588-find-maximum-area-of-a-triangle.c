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
    
    // Iterate through all pairs of points to find parallel lines with the x or y axis
    for (int i = 0; i < coordsSize; i++) {
        for (int j = i + 1; j < coordsSize; j++) {
            if (coords[i][0] == coords[j][0]) { // x-axis parallel, same x-coordinate
                for (int k = 0; k < coordsSize; k++) {
                    if (k != i && k != j && (coords[k][1] == coords[i][1] || coords[k][1] == coords[j][1])) {
                        long long base = abs(coords[j][1] - coords[i][1]);
                        long long height = abs(coords[k][0] - coords[i][0]);
                        long long area = base * height;
                        if (area > maxArea) {
                            maxArea = area;
                        }
                    }
                }
            } else if (coords[i][1] == coords[j][1]) { // y-axis parallel, same y-coordinate
                for (int k = 0; k < coordsSize; k++) {
                    if (k != i && k != j && (coords[k][0] == coords[i][0] || coords[k][0] == coords[j][0])) {
                        long long base = abs(coords[j][0] - coords[i][0]);
                        long long height = abs(coords[k][1] - coords[i][1]);
                        long long area = base * height;
                        if (area > maxArea) {
                            maxArea = area;
                        }
                    }
                }
            }
        }
    }
    
    return maxArea == -1 ? -1 : 2 * maxArea;
}


/*
 You are given an array points where points[i] = [xi, yi] represents the coordinates of a point on an infinite plane.
 Your task is to find the maximum area of a rectangle that:
 Can be formed using four of these points as its corners.
 Does not contain any other point inside or on its border.
 Has its edges parallel to the axes.
 Return the maximum area that you can obtain or -1 if no such rectangle is possible.
 Example 1:
 Input: points = [[1,1],[1,3],[3,1],[3,3]]
 Output: 4
 Explanation:
 We can make a rectangle with these 4 points as corners and there is no other point that lies inside or on the border. Hence, the maximum possible area would be 4.
 Example 2:
 Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
 Output: -1
 Explanation:
 There is only one rectangle possible is with points [1,1], [1,3], [3,1] and [3,3] but [2,2] will always lie inside it. Hence, returning -1.
 Example 3:
 Input: points = [[1,1],[1,3],[3,1],[3,3],[1,2],[3,2]]
 Output: 2
 Explanation:
 The maximum area rectangle is formed by the points [1,3], [1,2], [3,2], [3,3], which has an area of 2. Additionally, the points [1,1], [1,2], [3,1], [3,2] also form a valid rectangle with the same area.
 Constraints:
 1 <= points.length <= 10
 points[i].length == 2
 0 <= xi, yi <= 100
 All the given points are unique.
*/
// Helper function to check if a point is inside the rectangle
int isPointInsideRectangle(int x1, int y1, int x2, int y2, int x, int y) {
    return x > x1 && x < x2 && y > y1 && y < y2;
}

// Function to find the maximum area of a rectangle
int maxRectangleArea(int** points, int pointsSize, int* pointsColSize) {
    int maxArea = -1;

    // Iterate through all combinations of four points
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                for (int l = k + 1; l < pointsSize; l++) {
                    int x[] = {points[i][0], points[j][0], points[k][0], points[l][0]};
                    int y[] = {points[i][1], points[j][1], points[k][1], points[l][1]};

                    // Check if points form a rectangle
                    if ((x[0] == x[1] && x[2] == x[3] && y[0] == y[2] && y[1] == y[3]) ||
                        (x[0] == x[2] && x[1] == x[3] && y[0] == y[1] && y[2] == y[3])) {
                        
                        int area = abs((x[0] - x[2]) * (y[0] - y[1]));
                        
                        // Check if any other point is inside or on the border of the rectangle
                        int valid = 1;
                        for (int m = 0; m < pointsSize; m++) {
                            if (m != i && m != j && m != k && m != l &&
                                isPointInsideRectangle(x[0], y[0], x[2], y[1], points[m][0], points[m][1])) {
                                valid = 0;
                                break;
                            }
                        }

                        if (valid && area > maxArea) {
                            maxArea = area;
                        }
                    }
                }
            }
        }
    }
    
    return maxArea;
}
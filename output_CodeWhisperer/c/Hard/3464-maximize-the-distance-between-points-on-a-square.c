/*
 You are given an integer side, representing the edge length of a square with corners at (0, 0), (0, side), (side, 0), and (side, side) on a Cartesian plane.
 You are also given a positive integer k and a 2D integer array points, where points[i] = [xi, yi] represents the coordinate of a point lying on the boundary of the square.
 You need to select k elements among points such that the minimum Manhattan distance between any two points is maximized.
 Return the maximum possible minimum Manhattan distance between the selected k points.
 The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
 Example 1:
 Input: side = 2, points = [[0,2],[2,0],[2,2],[0,0]], k = 4
 Output: 2
 Explanation:
 Select all four points.
 Example 2:
 Input: side = 2, points = [[0,0],[1,2],[2,0],[2,2],[2,1]], k = 4
 Output: 1
 Explanation:
 Select the points (0, 0), (2, 0), (2, 2), and (2, 1).
 Example 3:
 Input: side = 2, points = [[0,0],[0,1],[0,2],[1,2],[2,0],[2,2],[2,1]], k = 5
 Output: 1
 Explanation:
 Select the points (0, 0), (0, 1), (0, 2), (1, 2), and (2, 2).
 Constraints:
 1 <= side <= 109
 4 <= points.length <= min(4 * side, 15 * 103)
 points[i] == [xi, yi]
 The input is generated such that:
 points[i] lies on the boundary of the square.
 All points[i] are unique.
 4 <= k <= min(25, points.length)
*/
int check(int** points, int pointsSize, int k, int dist) {
    int count = 1;
    int last = 0;
    
    for(int i = 1; i < pointsSize; i++) {
        int manhattan = abs(points[i][0] - points[last][0]) + abs(points[i][1] - points[last][1]);
        if(manhattan >= dist) {
            count++;
            last = i;
        }
    }
    
    return count >= k;
}

int maxDistance(int side, int** points, int pointsSize, int* pointsColSize, int k) {
    // Sort points by x coordinate
    for(int i = 0; i < pointsSize; i++) {
        for(int j = i + 1; j < pointsSize; j++) {
            if(points[i][0] > points[j][0]) {
                int tempx = points[i][0];
                int tempy = points[i][1];
                points[i][0] = points[j][0];
                points[i][1] = points[j][1];
                points[j][0] = tempx;
                points[j][1] = tempy;
            }
        }
    }
    
    int left = 0;
    int right = 2 * side;
    int result = 0;
    
    // Binary search on the minimum manhattan distance
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(check(points, pointsSize, k, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}    
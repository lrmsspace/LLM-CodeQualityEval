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

int minimumDistance(int** points, int pointsSize, int* pointsColSize) {
    int min_x = points[0][0], max_x = points[0][0];
    int min_y = points[0][1], max_y = points[0][1];
    
    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] < min_x) min_x = points[i][0];
        if (points[i][0] > max_x) max_x = points[i][0];
        if (points[i][1] < min_y) min_y = points[i][1];
        if (points[i][1] > max_y) max_y = points[i][1];
    }
    
    int max_distance = (max_x - min_x) + (max_y - min_y);
    
    for (int i = 0; i < pointsSize; i++) {
        int x = points[i][0], y = points[i][1];
        
        int new_min_x = min_x, new_max_x = max_x;
        int new_min_y = min_y, new_max_y = max_y;
        
        if (x == min_x || x == max_x) {
            if (x == min_x) {
                new_min_x = x == min_x ? max_x : min_x;
            } else {
                new_max_x = x == max_x ? min_x : max_x;
            }
        }
        
        if (y == min_y || y == max_y) {
            if (y == min_y) {
                new_min_y = y == min_y ? max_y : min_y;
            } else {
                new_max_y = y == max_y ? min_y : max_y;
            }
        }
        
        int current_distance = (new_max_x - new_min_x) + (new_max_y - new_min_y);
        if (current_distance < max_distance) {
            max_distance = current_distance;
        }
    }
    
    return max_distance;    
}
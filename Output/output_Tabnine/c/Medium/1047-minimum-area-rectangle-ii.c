/**https://leetcode.com/problems/minimum-area-rectangle-ii/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.
//Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: points = [[1,2],[2,1],[1,0],[0,1]]
//Output: 2.00000
//Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
//Example 2:
//Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
//Output: 1.00000
//Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
//Example 3:
//Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
//Output: 0
//Explanation: There is no possible rectangle to form from these points.
// 
//Constraints:
//	1 <= points.length <= 50
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
double minAreaFreeRect(int** points, int pointsSize, int* pointsColSize) {
    // Sort the points by their x-coordinates and then by their y-coordinates
    qsort(points, pointsSize, sizeof(points[0]), compare);
    
    // Create a map to store the distances between the points
    unordered_map<double, unordered_map<double, int>> distances;
    
    // Iterate through the sorted points
    for (int i = 0; i < pointsSize - 1; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            double dx = points[j][0] - points[i][0];
            double dy = points[j][1] - points[i][1];
            
            // If the points are collinear, skip to the next pair
            if (dx == 0 && dy == 0) {
                continue;
            }
            
            // Calculate the distance between the points
            double distance = sqrt(dx * dx + dy * dy);
            
            // Update the map with the distance and the count of points with that distance
            distances[dx][dy]++;
        }
    }
    
    double minArea = numeric_limits<double>::max();
    
    // Iterate through the distances in the map
    for (auto& distanceX : distances) {
        for (auto& distanceY : distanceX.second) {
            int count = distanceY.second;
            
            // If the distance is 0 (points are collinear), skip to the next pair
            if (distanceX.first == 0 && distanceY.first == 0) {
                continue;
            }
            
            // Check if there are enough points with the given distance to form a rectangle
            if (count >= 2) {
                double area = distanceX.first * distanceY.first / 2;
                
                // Update the minimum area if necessary
                minArea = min(minArea, area);
            }
        }
    }
    
    return minArea;
}
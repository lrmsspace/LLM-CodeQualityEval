/**https://leetcode.com/problems/minimum-area-rectangle/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.
// 
//Example 1:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
//Output: 4
//Example 2:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
//Output: 2
// 
//Constraints:
//	1 <= points.length <= 500
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
int minAreaRect(int** points, int pointsSize, int* pointsColSize) {
    // Convert the 2D points into a 1D array for easier manipulation
    int* flattenedPoints = malloc(pointsSize * pointsColSize[0] * sizeof(int));
    int index = 0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = 0; j < pointsColSize[0]; j++) {
            flattenedPoints[index++] = points[i][j];
        }
    }
    
    // Sort the points in ascending order based on their x-coordinates
    qsort(flattenedPoints, pointsSize * pointsColSize[0], sizeof(int), compareX);
    
    // Initialize variables to track the minimum area
    int minArea = INT_MAX;
    int left = 0;
    
    // Use two pointers, one for the leftmost point and one for the rightmost point, to find the minimum area
    for (int right = 1; right < pointsSize * pointsColSize[0]; right++) {
        // Skip duplicates
        if (flattenedPoints[left] == flattenedPoints[right]) {
            left++;
            continue;
        }
        
        // Try to find a pair of points that form a rectangle
        int yDiff = flattenedPoints[right] - flattenedPoints[left];
        int area = yDiff * (right - left);
        
        // Update the minimum area if necessary
        if (area < minArea) {
            minArea = area;
        }
        
        // Move the left pointer to the right if the rectangle formed with the current rightmost point is not valid
        while (left < right && flattenedPoints[right] - flattenedPoints[left] >= yDiff) {
            left++;
        }
    }
    
    free(flattenedPoints);
    return minArea;
    
}
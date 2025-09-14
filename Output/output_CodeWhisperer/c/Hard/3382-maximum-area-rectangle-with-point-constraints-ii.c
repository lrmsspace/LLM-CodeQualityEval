/*
 There are n points on an infinite plane. You are given two integer arrays xCoord and yCoord where (xCoord[i], yCoord[i]) represents the coordinates of the ith point.
 Your task is to find the maximum area of a rectangle that:
 Can be formed using four of these points as its corners.
 Does not contain any other point inside or on its border.
 Has its edges parallel to the axes.
 Return the maximum area that you can obtain or -1 if no such rectangle is possible.
 Example 1:
 Input: xCoord = [1,1,3,3], yCoord = [1,3,1,3]
 Output: 4
 Explanation:
 We can make a rectangle with these 4 points as corners and there is no other point that lies inside or on the border. Hence, the maximum possible area would be 4.
 Example 2:
 Input: xCoord = [1,1,3,3,2], yCoord = [1,3,1,3,2]
 Output: -1
 Explanation:
 There is only one rectangle possible is with points [1,1], [1,3], [3,1] and [3,3] but [2,2] will always lie inside it. Hence, returning -1.
 Example 3:
 Input: xCoord = [1,1,3,3,1,3], yCoord = [1,3,1,3,2,2]
 Output: 2
 Explanation:
 The maximum area rectangle is formed by the points [1,3], [1,2], [3,2], [3,3], which has an area of 2. Additionally, the points [1,1], [1,2], [3,1], [3,2] also form a valid rectangle with the same area.
 Constraints:
 1 <= xCoord.length == yCoord.length <= 2 * 105
 0 <= xCoord[i], yCoord[i] <= 8 * 107
 All the given points are unique.
*/

long long maxRectangleArea(int* xCoord, int xCoordSize, int* yCoord, int yCoordSize) {
    long long maxArea = -1;
    
    // Check all possible pairs of points
    for(int i = 0; i < xCoordSize; i++) {
        for(int j = i + 1; j < xCoordSize; j++) {
            // Skip if points have same x or y coordinate
            if(xCoord[i] == xCoord[j] || yCoord[i] == yCoord[j]) continue;
            
            // Find the other two corner points
            int x1 = xCoord[i], y1 = yCoord[i];
            int x2 = xCoord[j], y2 = yCoord[j];
            int x3 = x1, y3 = y2;
            int x4 = x2, y4 = y1;
            
            // Check if corner points exist in input
            int corner3 = 0, corner4 = 0;
            for(int k = 0; k < xCoordSize; k++) {
                if(xCoord[k] == x3 && yCoord[k] == y3) corner3 = 1;
                if(xCoord[k] == x4 && yCoord[k] == y4) corner4 = 1;
            }
            
            if(!corner3 || !corner4) continue;
            
            // Check if any point lies inside rectangle
            int valid = 1;
            int minX = x1 < x2 ? x1 : x2;
            int maxX = x1 > x2 ? x1 : x2;
            int minY = y1 < y2 ? y1 : y2;
            int maxY = y1 > y2 ? y1 : y2;
            
            for(int k = 0; k < xCoordSize; k++) {
                if(xCoord[k] > minX && xCoord[k] < maxX && 
                   yCoord[k] > minY && yCoord[k] < maxY) {
                    valid = 0;
                    break;
                }
            }
            
            if(valid) {
                long long area = (long long)abs(x1 - x2) * abs(y1 - y2);
                maxArea = maxArea < area ? area : maxArea;
            }
        }
    }
    
    return maxArea;
}    
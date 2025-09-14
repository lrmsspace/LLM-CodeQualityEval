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
    for (int i = 0; i < xCoordSize; i++) {
        for (int j = i + 1; j < xCoordSize; j++) {
            for (int k = 0; k < yCoordSize; k++) {
                for (int l = k + 1; l < yCoordSize; l++) {
                    long long x1 = xCoord[i], x2 = xCoord[j];
                    long long y1 = yCoord[k], y2 = yCoord[l];
                    
                    if (x1 == x2 || y1 == y2) continue; // Skip if points are not distinct
                    
                    long long area = (x2 - x1) * (y2 - y1);
                    
                    // Check if any point lies inside or on the border of the rectangle
                    int valid = 1;
                    for (int m = 0; m < xCoordSize; m++) {
                        if ((xCoord[m] > x1 && xCoord[m] < x2) && (yCoord[m] > y1 && yCoord[m] < y2)) {
                            valid = 0;
                            break;
                        }
                    }
                    
                    if (valid) {
                        maxArea = maxArea > area ? maxArea : area;
                    }
                }
            }
        }
    }
    
    return maxArea;    
}
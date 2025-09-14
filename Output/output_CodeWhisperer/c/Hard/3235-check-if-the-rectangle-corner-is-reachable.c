/*
 You are given two positive integers xCorner and yCorner, and a 2D array circles, where circles[i] = [xi, yi, ri] denotes a circle with center at (xi, yi) and radius ri.
 There is a rectangle in the coordinate plane with its bottom left corner at the origin and top right corner at the coordinate (xCorner, yCorner). You need to check whether there is a path from the bottom left corner to the top right corner such that the entire path lies inside the rectangle, does not touch or lie inside any circle, and touches the rectangle only at the two corners.
 Return true if such a path exists, and false otherwise.
 Example 1:
 Input: xCorner = 3, yCorner = 4, circles = [[2,1,1]]
 Output: true
 Explanation:
 The black curve shows a possible path between (0, 0) and (3, 4).
 Example 2:
 Input: xCorner = 3, yCorner = 3, circles = [[1,1,2]]
 Output: false
 Explanation:
 No path exists from (0, 0) to (3, 3).
 Example 3:
 Input: xCorner = 3, yCorner = 3, circles = [[2,1,1],[1,2,1]]
 Output: false
 Explanation:
 No path exists from (0, 0) to (3, 3).
 Example 4:
 Input: xCorner = 4, yCorner = 4, circles = [[5,5,1]]
 Output: true
 Explanation:
 Constraints:
 3 <= xCorner, yCorner <= 109
 1 <= circles.length <= 1000
 circles[i].length == 3
 1 <= xi, yi, ri <= 109
*/

bool canReachCorner(int xCorner, int yCorner, int** circles, int circlesSize, int* circlesColSize) {
    // Check if start or end point lies inside any circle
    for(int i = 0; i < circlesSize; i++) {
        long long x = circles[i][0];
        long long y = circles[i][1];
        long long r = circles[i][2];
        
        // Check start point (0,0)
        if(x*x + y*y <= r*r) return false;
        
        // Check end point (xCorner,yCorner) 
        long long dx = x - xCorner;
        long long dy = y - yCorner;
        if(dx*dx + dy*dy <= r*r) return false;
    }

    // Check if line segment from (0,0) to (xCorner,yCorner) intersects any circle
    for(int i = 0; i < circlesSize; i++) {
        long long x = circles[i][0];
        long long y = circles[i][1]; 
        long long r = circles[i][2];
        
        // Vector from start to end point
        long long dx = xCorner;
        long long dy = yCorner;
        
        // Vector from circle center to start point
        long long cx = -x;
        long long cy = -y;
        
        // Length of line segment squared
        long long d2 = dx*dx + dy*dy;
        
        // Dot product of line vector and circle-to-start vector
        long long t = cx*dx + cy*dy;
        
        // Find closest point on line segment to circle center
        if(d2 > 0) {
            t = t < 0 ? 0 : (t > d2 ? d2 : t);
            long long px = t*dx/d2;
            long long py = t*dy/d2;
            long long dist2 = (cx+px)*(cx+px) + (cy+py)*(cy+py);
            if(dist2 <= r*r) return false;
        }
    }
    
    return true;
}    
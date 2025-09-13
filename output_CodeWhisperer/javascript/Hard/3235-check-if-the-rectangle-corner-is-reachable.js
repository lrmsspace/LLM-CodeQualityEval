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

/**
 * @param {number} xCorner
 * @param {number} yCorner
 * @param {number[][]} circles
 * @return {boolean}
 */
var canReachCorner = function(xCorner, yCorner, circles) {
    const isInsideCircle = (x, y, circle) => {
        const [xCenter, yCenter, radius] = circle;
        const distance = Math.sqrt((x - xCenter) ** 2 + (y - yCenter) ** 2);
        return distance <= radius;
    };
    
    const isInsideRectangle = (x, y) => {
        return x >= 0 && x <= xCorner && y >= 0 && y <= yCorner;
    };
    
    const isInsideAnyCircle = (x, y) => {
        return circles.some(circle => isInsideCircle(x, y, circle));
    };
    
    const dfs = (x, y, visited) => {
        if (isInsideAnyCircle(x, y) || visited.has(`${x},${y}`)) {
            return false;
        }
        
        if (x === xCorner && y === yCorner) {
            return true;
        }
        
        visited.add(`${x},${y}`);
        
        const dx = [0, 0, 1, -1];
        const dy = [1, -1, 0, 0];
        
        for (let i = 0; i < 4; i++) {
            const newX = x + dx[i];
            const newY = y + dy[i];
            
            if (isInsideRectangle(newX, newY) && dfs(newX, newY, visited)) {
                return true;
            }
        }
        
        return false;
    };
    
    return dfs(0, 0, new Set());
        
};
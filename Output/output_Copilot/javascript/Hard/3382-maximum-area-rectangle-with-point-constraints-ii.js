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

/**
 * @param {number[]} xCoord
 * @param {number[]} yCoord
 * @return {number}
 */
var maxRectangleArea = function(xCoord, yCoord) {
    const n = xCoord.length;
    const points = Array.from({ length: n }, (_, i) => [xCoord[i], yCoord[i]]);
    
    // Sort points by x-coordinate, then by y-coordinate
    points.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
    
    let maxArea = -1;
    
    // Use a set to track y-coordinates of points
    const ySet = new Set();
    
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (points[i][0] === points[j][0]) continue; // Skip if x-coordinates are the same
            
            // Check if we can form a rectangle with these two points
            const y1 = points[i][1];
            const y2 = points[j][1];
            
            if (ySet.has(y1) && ySet.has(y2)) {
                const area = Math.abs(points[j][0] - points[i][0]) * Math.abs(y2 - y1);
                maxArea = Math.max(maxArea, area);
            }
        }
        ySet.add(points[i][1]); // Add current point's y-coordinate to the set
    }
    
    return maxArea;
        
};
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

/**
 * @param {number[][]} points
 * @return {number}
 */
var maxRectangleArea = function(points) {
    // Sort the points based on their x-coordinates
    points.sort((a, b) => a[0] - b[0]);
    
    // Initialize the stack with the points sorted by x-coordinates
    let stack = [];
    let maxArea = 0;    
    for (let i = 0; i < points.length; i++) {
        // Pop the stack until the current point's x-coordinate is less than or equal to the top of the stack
        while (stack.length > 0 && points[i][0] >= points[stack[stack.length - 1]][0]) {
            let height = points[stack.pop()][1];
            let width = i - (stack.length > 0? stack[stack.length - 1] : -1) - 1;
            maxArea = Math.max(maxArea, height * width);
        }
        
        // Push the current point into the stack
        stack.push(i);
    }
    // Pop the remaining points in the stack
    while (stack.length > 0) {
        let height = points[stack.pop()][1];
        let width = points.length - (stack.length > 0? stack[stack.length - 1] : -1) - 1;
        maxArea = Math.max(maxArea, height * width);
    }
    
    return maxArea;
    
    
};
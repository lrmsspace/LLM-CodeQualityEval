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
    const n = points.length;
    if (n < 4) return -1; // Not enough points to form a rectangle

    let maxArea = -1;

    // Create a set for quick lookup
    const pointSet = new Set(points.map(p => p.join(',')));

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            for (let k = j + 1; k < n; k++) {
                for (let l = k + 1; l < n; l++) {
                    const p1 = points[i], p2 = points[j], p3 = points[k], p4 = points[l];

                    // Check if they can form a rectangle
                    if ((p1[0] === p2[0] && p3[0] === p4[0] && p1[1] === p3[1] && p2[1] === p4[1]) ||
                        (p1[0] === p3[0] && p2[0] === p4[0] && p1[1] === p2[1] && p3[1] === p4[1]) ||
                        (p1[0] === p4[0] && p2[0] === p3[0] && p1[1] === p2[1] && p3[1] === p4[1])) {

                        // Calculate area
                        const width = Math.abs(p2[0] - p1[0]);
                        const height = Math.abs(p3[1] - p2[1]);
                        const area = width * height;

                        // Check if the rectangle is valid
                        if (area > 0 && !pointSet.has([p2[0], p3[1]].join(',')) &&
                            !pointSet.has([p3[0], p2[1]].join(','))) {
                            maxArea = Math.max(maxArea, area);
                        }
                    }
                }
            }
        }
    }

    return maxArea;
        
};
/*
 You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].
 Count the number of pairs of points (A, B), where
 A is on the upper left side of B, and
 there are no other points in the rectangle (or line) they make (including the border).
 Return the count.
 Example 1:
 Input: points = [[1,1],[2,2],[3,3]]
 Output: 0
 Explanation:
 There is no way to choose A and B so A is on the upper left side of B.
 Example 2:
 Input: points = [[6,2],[4,4],[2,6]]
 Output: 2
 Explanation:
 The left one is the pair (points[1], points[0]), where points[1] is on the upper left side of points[0] and the rectangle is empty.
 The middle one is the pair (points[2], points[1]), same as the left one it is a valid pair.
 The right one is the pair (points[2], points[0]), where points[2] is on the upper left side of points[0], but points[1] is inside the rectangle so it's not a valid pair.
 Example 3:
 Input: points = [[3,1],[1,3],[1,1]]
 Output: 2
 Explanation:
 The left one is the pair (points[2], points[0]), where points[2] is on the upper left side of points[0] and there are no other points on the line they form. Note that it is a valid state when the two points form a line.
 The middle one is the pair (points[1], points[2]), it is a valid pair same as the left one.
 The right one is the pair (points[1], points[0]), it is not a valid pair as points[2] is on the border of the rectangle.
 Constraints:
 2 <= n <= 50
 points[i].length == 2
 0 <= points[i][0], points[i][1] <= 50
 All points[i] are distinct.
*/

/**
 * @param {number[][]} points
 * @return {number}
 */
var numberOfPairs = function(points) {
    const n = points.length;
    let count = 0;

    // Sort points by x-coordinate, then by y-coordinate
    points.sort((a, b) => a[0] - b[0] || a[1] - b[1]);

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const [x1, y1] = points[i];
            const [x2, y2] = points[j];

            // Check if point i is on the upper left side of point j
            if (x1 < x2 && y1 < y2) {
                let validPair = true;

                // Check if there are any points in the rectangle formed by (x1, y1) and (x2, y2)
                for (let k = 0; k < n; k++) {
                    if (k !== i && k !== j) {
                        const [xk, yk] = points[k];
                        if (xk >= x1 && xk <= x2 && yk >= y1 && yk <= y2) {
                            validPair = false;
                            break;
                        }
                    }
                }

                if (validPair) {
                    count++;
                }
            }
        }
    }

    return count;
        
};
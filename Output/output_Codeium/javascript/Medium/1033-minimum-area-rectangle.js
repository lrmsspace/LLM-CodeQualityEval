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
/**
 * @param {number[][]} points
 * @return {number}
 */
var minAreaRect = function(points) {
    const map = new Map();
    for (const [x, y] of points) {
        if (map.has(x)) {
            map.get(x).add(y);
        } else {
            map.set(x, new Set([y]));
        }
    }
    let result = Infinity;
    for (const [x1, ys1] of map) {
        for (const [x2, ys2] of map) {
            if (x1 !== x2) {
                const ys1Arr = Array.from(ys1);
                const ys2Arr = Array.from(ys2);
                ys1Arr.sort((a, b) => a - b);
                ys2Arr.sort((a, b) => a - b);
                let i = 0, j = 0;
                while (i < ys1Arr.length && j < ys2Arr.length) {
                    if (ys1Arr[i] === ys2Arr[j]) {
                        result = Math.min(result, Math.abs(x1 - x2));
                        i++;
                        j++;
                    } else if (ys1Arr[i] < ys2Arr[j]) {
                        i++;
                    } else {
                        j++;
                    }
                }
            }
        }
    }
    return result === Infinity ? 0 : result;
};
/**https://leetcode.com/problems/rectangle-area-ii/ */
//You are given a 2D array of axis-aligned rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] denotes the ith rectangle where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner.
//Calculate the total area covered by all rectangles in the plane. Any area covered by two or more rectangles should only be counted once.
//Return the total area. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
//Output: 6
//Explanation: A total area of 6 is covered by all three rectangles, as illustrated in the picture.
//From (1,1) to (2,2), the green and red rectangles overlap.
//From (1,0) to (2,3), all three rectangles overlap.
//Example 2:
//Input: rectangles = [[0,0,1000000000,1000000000]]
//Output: 49
//Explanation: The answer is 1018 modulo (109 + 7), which is 49.
// 
//Constraints:
//	1 <= rectangles.length <= 200
//	rectanges[i].length == 4
//	0 <= xi1, yi1, xi2, yi2 <= 109
//	xi1 <= xi2
//	yi1 <= yi2
/**
 * @param {number[][]} rectangles
 * @return {number}
 */
var rectangleArea = function(rectangles) {
    const MOD = 1000000007;
    const n = rectangles.length;
    const xs = new Set();
    for (const rect of rectangles) {
        xs.add(rect[0]);
        xs.add(rect[2]);
    }
    const xVals = Array.from(xs).sort((a, b) => a - b);
    let xIndex = new Map();
    for (let i = 0; i < xVals.length; i++) {
        xIndex.set(xVals[i], i);
    }
    const count = new Array(xVals.length).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        const rect = rectangles[i];
        const x1 = xIndex.get(rect[0]);
        const x2 = xIndex.get(rect[2]);
        for (let x = x1; x < x2; x++) {
            count[x][i]++;
        }
    }
    let ans = 0;
    for (let i = 0; i < xVals.length - 1; i++) {
        const x = xVals[i];
        let active = 0;
        let y1 = 0, y2 = 0;
        for (let j = 0; j < n; j++) {
            if (count[i][j] > 0) {
                y1 = Math.max(y1, rectangles[j][1]);
                y2 = Math.min(y2 > 0 ? y2 : Number.MAX_SAFE_INTEGER, rectangles[j][3]);
                active += count[i][j] == 1 ? 1 : 0;
                if (active > 0) {
                    ans += (y2 - y1) * (xVals[i + 1] - x);
                    ans %= MOD;
                }
            }
        }
    }
    return ans;
};
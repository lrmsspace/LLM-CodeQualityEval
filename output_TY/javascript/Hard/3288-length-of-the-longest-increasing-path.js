/*
 You are given a 2D array of integers coordinates of length n and an integer k, where 0 <= k < n.
 coordinates[i] = [xi, yi] indicates the point (xi, yi) in a 2D plane.
 An increasing path of length m is defined as a list of points (x1, y1), (x2, y2), (x3, y3), ..., (xm, ym) such that:
 xi < xi + 1 and yi < yi + 1 for all i where 1 <= i < m.
 (xi, yi) is in the given coordinates for all i where 1 <= i <= m.
 Return the maximum length of an increasing path that contains coordinates[k].
 Example 1:
 Input: coordinates = [[3,1],[2,2],[4,1],[0,0],[5,3]], k = 1
 Output: 3
 Explanation:
 (0, 0), (2, 2), (5, 3) is the longest increasing path that contains (2, 2).
 Example 2:
 Input: coordinates = [[2,1],[7,0],[5,6]], k = 2
 Output: 2
 Explanation:
 (2, 1), (5, 6) is the longest increasing path that contains (5, 6).
 Constraints:
 1 <= n == coordinates.length <= 105
 coordinates[i].length == 2
 0 <= coordinates[i][0], coordinates[i][1] <= 109
 All elements in coordinates are distinct.
 0 <= k <= n - 1
*/

/**
 * @param {number[][]} coordinates
 * @param {number} k
 * @return {number}
 */
var maxPathLength = function(coordinates, k) {
    let n = coordinates.length;
    let dp = new Array(n).fill(0).map(() => new Array(k + 1).fill(0));
    let x = new Map();
    let y = new Map();
    for (let i = 0; i < n; i++) {
        let [a, b] = coordinates[i];
        if (!x.has(a)) x.set(a, []);
        if (!y.has(b)) y.set(b, []);
        x.get(a).push(i);
        y.get(b).push(i);
    }
    let ans = 0;
    for (let i = 0; i < n; i++) {
        let [a, b] = coordinates[i];
        for (let j = 0; j <= k; j++) {
            dp[i][j] = Math.max(dp[i][j], j * j);
        }
        for (let j = 1; j <= k; j++) {
            for (let idx of x.get(a)) {
                if (idx == i) continue;
                let [x1, y1] = coordinates[idx];
                dp[i][j] = Math.max(dp[i][j], dp[idx][j - 1] + (x1 - a) * (x1 - a));
            }
        }
    }
    return Math.max(...dp[n - 1]);
};
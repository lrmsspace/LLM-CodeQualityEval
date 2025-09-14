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
    const n = coordinates.length;
    const dp = new Array(n).fill(0).map(() => new Array(n).fill(0));
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    let maxLen = 1;
    
    const dfs = (i, j) => {
        if (dp[i][j]) return dp[i][j];
        dp[i][j] = 1;
        for (const [dx, dy] of directions) {
            const x = i + dx, y = j + dy;
            if (x >= 0 && x < n && y >= 0 && y < n && coordinates[x][0] > coordinates[i][0] && coordinates[x][1] > coordinates[i][1]) {
                dp[i][j] = Math.max(dp[i][j], 1 + dfs(x, y));
            }
        }
        return dp[i][j];
    };
    
    for (let i = 0; i < n; i++) {
        maxLen = Math.max(maxLen, dfs(i, i));
    }
    
    return maxLen;
        
};
/*
 You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.
 Return the minimum possible sum of the area of these rectangles.
 Note that the rectangles are allowed to touch.
 Example 1:
 Input: grid = [[1,0,1],[1,1,1]]
 Output: 5
 Explanation:
 The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
 The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
 The 1 at (1, 1) is covered by a rectangle of area 1.
 Example 2:
 Input: grid = [[1,0,1,0],[0,1,0,1]]
 Output: 5
 Explanation:
 The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
 The 1 at (1, 1) is covered by a rectangle of area 1.
 The 1 at (1, 3) is covered by a rectangle of area 1.
 Constraints:
 1 <= grid.length, grid[i].length <= 30
 grid[i][j] is either 0 or 1.
 The input is generated such that there are at least three 1's in grid.
*/

/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumSum = function(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const ones = [];

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (grid[i][j] === 1) {
                ones.push([i, j]);
            }
        }
    }

    if (ones.length < 3) return 0;

    let minSum = Infinity;

    const calculateArea = (r1, c1, r2, c2) => {
        return (r2 - r1 + 1) * (c2 - c1 + 1);
    };

    const dfs = (index, selected) => {
        if (selected.length === 3) {
            let areaSum = 0;
            for (const rect of selected) {
                const [r1, c1, r2, c2] = rect;
                areaSum += calculateArea(r1, c1, r2, c2);
            }
            minSum = Math.min(minSum, areaSum);
            return;
        }

        if (index >= ones.length) return;

        const [r, c] = ones[index];
        for (let i = index; i < ones.length; i++) {
            const [r2, c2] = ones[i];
            for (let j = 0; j < selected.length; j++) {
                const [r1, c1, r3, c3] = selected[j];
                if (r1 <= r && r <= r3 && c1 <= c && c <= c3) {
                    dfs(i + 1, selected);
                    return;
                }
            }
            selected.push([r, c, r2, c2]);
            dfs(i + 1, selected);
            selected.pop();
        }
    };

    dfs(0, []);
    return minSum;

};
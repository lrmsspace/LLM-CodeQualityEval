/**https://leetcode.com/problems/last-day-where-you-can-still-cross/ */
//There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.
//Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).
//You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).
//Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.
// 
//Example 1:
//Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
//Output: 2
//Explanation: The above image depicts how the matrix changes each day starting from day 0.
//The last day where it is possible to cross from top to bottom is on day 2.
//Example 2:
//Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
//Output: 1
//Explanation: The above image depicts how the matrix changes each day starting from day 0.
//The last day where it is possible to cross from top to bottom is on day 1.
//Example 3:
//Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
//Output: 3
//Explanation: The above image depicts how the matrix changes each day starting from day 0.
//The last day where it is possible to cross from top to bottom is on day 3.
// 
//Constraints:
//	2 <= row, col <= 2 * 104
//	4 <= row * col <= 2 * 104
//	cells.length == row * col
//	1 <= ri <= row
//	1 <= ci <= col
//	All the values of cells are unique.


bool dfs(int water[][col], bool visited[][col], int r, int c, int row, int col) {
    if (r == row - 1) return true;
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < 0 || nr >= row || nc < 0 || nc >= col || water[nr][nc] || visited[nr][nc]) continue;
        visited[nr][nc] = true;
        if (dfs(water, visited, nr, nc, row, col)) return true;
    }
    return false;
}

bool canCross(int water[][col], int row, int col) {
    bool visited[row][col];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < col; ++i) {
        if (!water[0][i] && !visited[0][i]) {
            if (dfs(water, visited, 0, i, row, col)) return true;
        }
    }
    return false;   
}
int latestDayToCross(int row, int col, int** cells, int cellsSize, int* cellsColSize) {
    int water[row][col];
    memset(water, 0, sizeof(water));
    int maxDay = 0;
    for (int i = 0; i < cellsSize; ++i) {
        int r = cells[i][0] - 1, c = cells[i][1] - 1;
        water[r][c] = 1;
        maxDay = max(maxDay, i);
        if (canCross(water, row, col)) continue;
        while (i > 0 && !canCross(water, row, col)) {
            int r = cells[--i][0] - 1, c = cells[i][1] - 1;
            water[r][c] = 0;
        }
        maxDay = i;
    }
    return maxDay;
}
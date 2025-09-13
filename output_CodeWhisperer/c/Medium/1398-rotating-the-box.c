/**https://leetcode.com/problems/rotating-the-box/ */
//You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:
//	A stone '#'
//	A stationary obstacle '*'
//	Empty '.'
//The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.
//It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.
//Return an n x m matrix representing the box after the rotation described above.
// 
//Example 1:
//Input: boxGrid = [["#",".","#"]]
//Output: [["."],
//         ["#"],
//         ["#"]]
//Example 2:
//Input: boxGrid = [["#",".","*","."],
//              ["#","#","*","."]]
//Output: [["#","."],
//         ["#","#"],
//         ["*","*"],
//         [".","."]]
//Example 3:
//Input: boxGrid = [["#","#","*",".","*","."],
//              ["#","#","#","*",".","."],
//              ["#","#","#",".","#","."]]
//Output: [[".","#","#"],
//         [".","#","#"],
//         ["#","#","*"],
//         ["#","*","."],
//         ["#",".","*"],
//         ["#",".","."]]
// 
//Constraints:
//	m == boxGrid.length
//	n == boxGrid[i].length
//	1 <= m, n <= 500
//	boxGrid[i][j] is either '#', '*', or '.'.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** rotateTheBox(char** boxGrid, int boxGridSize, int* boxGridColSize, int* returnSize, int** returnColumnSizes) {
    int m = boxGridSize;
    int n = boxGridColSize[0];
    char** result = (char**)malloc(sizeof(char*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
        result[i] = (char*)malloc(sizeof(char) * n);
        for (int j = 0; j < n; j++) {
            result[i][j] = '.';
        }
    }
    for (int i = 0; i < m; i++) {
        int empty = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (boxGrid[i][j] == '#') {
                result[empty--][m - 1 - i] = '#';
            }
            else if (boxGrid[i][j] == '*') {
                empty = j - 1;
                result[j][m - 1 - i] = '*';
            }
        }
    }
    *returnSize = n;
    return result;
}
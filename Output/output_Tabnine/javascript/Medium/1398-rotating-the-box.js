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
 * @param {character[][]} boxGrid
 * @return {character[][]}
 */
var rotateTheBox = function(boxGrid) {
    const m = boxGrid.length;
    const n = boxGrid[0].length;
    const result = Array.from({length: n}, () => Array.from({length: m}, () => '*'));
    
    for (let j = n - 1; j >= 0; j--) {
        for (let i = m - 1; i >= 0; i--) {
            if (boxGrid[i][j] === '#') {
                result[j][m - 1 - i] = '#';
            } else if (boxGrid[i][j] === '*') {
                result[j][m - 1 - i] = '*';
            }
        }
    }
    
    return result;
    
};
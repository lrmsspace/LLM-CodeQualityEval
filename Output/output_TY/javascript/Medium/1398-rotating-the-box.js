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
    let n = boxGrid.length;
    let m = boxGrid[0].length;
    let result = Array(m).fill().map(() => Array(n).fill('.'));
    for(let i = 0; i < n; i++){
        let j = m - 1;
        while(j >= 0){
            if(boxGrid[i][j] === '.'){
                j--;
            }else if(boxGrid[i][j] === '*'){
                j = -1;
            }else{
                let k = j - 1;
                while(k >= 0 && boxGrid[i][k] === '.'){
                    result[k][i] = '#';
                }
            }
        }
    }
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            result[j][n - 1 - i] = boxGrid[i][j];
        }
    }
    return result;
};
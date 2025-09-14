/**https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/ */
//Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
// 
//Example 1:
//Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
//Output: true
//Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
//Example 2:
//Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
//Output: false
//Explanation: It is impossible to make mat equal to target by rotating mat.
//Example 3:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
//Output: true
//Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
// 
//Constraints:
//	n == mat.length == target.length
//	n == mat[i].length == target[i].length
//	1 <= n <= 10
//	mat[i][j] and target[i][j] are either 0 or 1.
/**
 * @param {number[][]} mat
 * @param {number[][]} target
 * @return {boolean}
 */
var findRotation = function(mat, target) {
    const n = mat.length;
    
    // Check if mat is equal to target
    if (JSON.stringify(mat) === JSON.stringify(target)) return true;
    
    // Rotate mat 90 degrees clockwise once
    const rotateOnce = () => {
        const newMat = [];
        for (let i = 0; i < n; i++) {
            const row = [];
            for (let j = n - 1; j >= 0; j--) {
                row.push(mat[j][i]);
            }
            newMat.push(row);
        }
        return newMat;
    };
    
    // Rotate mat 90 degrees clockwise twice
    const rotateTwice = () => rotateOnce().map(row => row.reverse());
    
    // Check if rotated mat is equal to target
    for (let i = 0; i < 2; i++) {
        if (JSON.stringify(rotateTwice()) === JSON.stringify(target)) return true;
        mat = rotateOnce();
    }
    
    return false;
    
};
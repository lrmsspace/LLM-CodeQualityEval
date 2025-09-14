/**https://leetcode.com/problems/first-completely-painted-row-or-column/ */
//You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
//Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
//Return the smallest index i at which either a row or a column will be completely painted in mat.
// 
//Example 1:
//Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
//Output: 2
//Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
//Example 2:
//Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
//Output: 3
//Explanation: The second column becomes fully painted at arr[3].
// 
//Constraints:
//	m == mat.length
//	n = mat[i].length
//	arr.length == m * n
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	1 <= arr[i], mat[r][c] <= m * n
//	All the integers of arr are unique.
//	All the integers of mat are unique.
/**
 * @param {number[]} arr
 * @param {number[][]} mat
 * @return {number}
 */
var firstCompleteIndex = function(arr, mat) {
    let m = mat.length;
    let n = mat[0].length;
    let rowFilled = new Array(m).fill(false);
    let colFilled = new Array(n).fill(false);
    
    for(let i = 0; i < arr.length; i++) {
        let row = Math.floor((arr[i]-1) / n);
        let col = (arr[i]-1) % n;
        
        if(!rowFilled[row]) {
            let count = 0;
            for(let j = 0; j < n; j++) {
                if(mat[row][j] === arr[i]) {
                    count++;
                    if(count === n) {
                        rowFilled[row] = true;
                        break;
                    }
                }
            }
        }
        
        if(!colFilled[col]) {
            let count = 0;
            for(let j = 0; j < m; j++) {
                if(mat[j][col] === arr[i]) {
                    count++;
                    if(count === m) {
                        colFilled[col] = true;
                        break;
                    }
                }
            }
        }
        
        if(rowFilled[row] && colFilled[col]) {
            return i;
        }

    }
    
    return -1;
    
};
/**https://leetcode.com/problems/n-queens/ */
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
// 
//Example 1:
//Input: n = 4
//Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
//Example 2:
//Input: n = 1
//Output: [["Q"]]
// 
//Constraints:
//	1 <= n <= 9
/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function(n) {
    let res = [];
    let board = new Array(n).fill(0).map(()=>new Array(n).fill('.'));
    let cols = new Set();
    let diag1 = new Set();
    let diag2 = new Set();
    
    const backtrack = (r) => {
        if(r === n){
            let temp = [];
            for(let i=0;i<n;i++){
                temp.push(board[i].join(''));
            }
            res.push(temp);
            return;
        }
        
        for(let c=0;c<n;c++){
            if(cols.has(c) || diag1.has(r-c) || diag2.has(r+c)) continue;
        }
    }
    
    for(let i=0;i<n;i++){
        backtrack(i);
    }
    return res;
};
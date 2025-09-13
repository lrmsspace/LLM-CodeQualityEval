/**https://leetcode.com/problems/push-dominoes/ */
//There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
//After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
//When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
//For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
//You are given a string dominoes representing the initial state where:
//	dominoes[i] = 'L', if the ith domino has been pushed to the left,
//	dominoes[i] = 'R', if the ith domino has been pushed to the right, and
//	dominoes[i] = '.', if the ith domino has not been pushed.
//Return a string representing the final state.
// 
//Example 1:
//Input: dominoes = "RR.L"
//Output: "RR.L"
//Explanation: The first domino expends no additional force on the second domino.
//Example 2:
//Input: dominoes = ".L.R...LR..L.."
//Output: "LL.RR.LLRRLL.."
// 
//Constraints:
//	n == dominoes.length
//	1 <= n <= 105
//	dominoes[i] is either 'L', 'R', or '.'.
/**
 * @param {string} dominoes
 * @return {string}
 */
var pushDominoes = function(dominoes) {
    const n = dominoes.length;
    let res = Array(n).fill('.');
    let left = Array(n).fill(0);
    let right = Array(n).fill(0);
    
    for (let i = 0; i < n - 1; i++) {
        if (dominoes[i] === 'R' && dominoes[i + 1] === 'L') {
            left[i + 1] = 1;
        } else if (dominoes[i] === 'L' && dominoes[i + 1] === 'R') {
            right[i] = 1;
        }
    }
    
    for (let i = n - 2; i >= 0; i--) {
        if (right[i + 1] === 1) {
            right[i] = 0;
        } else if (right[i] === 1 && dominoes[i + 1] === 'L') {
            right[i] = 0;
            left[i] = 1;
        }
    }
    
    for (let i = 0; i < n; i++) {
        if (left[i] === 1) {
            res[i] = 'L';
        } else if (right[i] === 1) {
            res[i] = 'R';
        }
    }
    
    return res.join('');
    
};
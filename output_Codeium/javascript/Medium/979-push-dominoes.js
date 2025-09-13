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
    let res = dominoes.split('');
    let l = -1, r = -1;
    for (let i = 0; i < res.length; i++) {
        if (res[i] === 'L') l = i;
        else if (res[i] === 'R') {
            if (l === -1) res[i] = 'R';
            else if (r !== -1) {
                let d1 = i - l;
                let d2 = r - i;
                if (d1 < d2) res[i] = 'R';
                else if (d1 > d2) res[i] = 'L';
                else res[i] = '.';
            } else {
                res[i] = 'R';
            }
            r = i;
        } else {
            if (l !== -1 && r !== -1) {
                let d1 = i - l;
                let d2 = r - i;
                if (d1 < d2) res[i] = 'R';
                else if (d1 > d2) res[i] = 'L';
                else res[i] = '.';
            } else if (l !== -1) {
                res[i] = 'L';
            } else if (r !== -1) {
                res[i] = 'R';
            } else {
                res[i] = '.';
            }
        }
    }
    if (r === -1) {
        while (res.length < dominoes.length) {
            res.push('L');
        }
    }
    return res.join('');
};
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
    let n = dominoes.length;
    let result = new Array(n).fill('.');
    let left = 0;
    let right = 0;
    
    while (right < n) {
        if (dominoes[right] === 'R') {
            left = right;
            while (right < n && dominoes[right] !== 'L') {
                right++;
            }
            if (right < n) {
                let mid = right - left - 1;
                if (mid % 2 === 0) {
                    result[left + Math.floor(mid / 2)] = 'R';
                    result[right - Math.floor(mid / 2) - 1] = 'L';
                } else {
                    result[left + Math.floor(mid / 2)] = 'R';
                    result[right - Math.floor(mid / 2) - 1] = 'L';
                }
            } else {
                for (let i = left; i < right; i++) {
                    result[i] = 'R';
                }
            }
        } else if (dominoes[right] === 'L') {
            for (let i = left; i < right; i++) {
                result[i] = 'L';
            }
        }
        right++;
    }
    
    return result.join('');    
};
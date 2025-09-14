/**https://leetcode.com/problems/maximum-swap/ */
//You are given an integer num. You can swap two digits at most once to get the maximum valued number.
//Return the maximum valued number you can get.
// 
//Example 1:
//Input: num = 2736
//Output: 7236
//Explanation: Swap the number 2 and the number 7.
//Example 2:
//Input: num = 9973
//Output: 9973
//Explanation: No swap.
// 
//Constraints:
//	0 <= num <= 108
/**
 * @param {number} num
 * @return {number}
 */
var maximumSwap = function(num) {
    let numStr = num.toString();
    let numArr = numStr.split('');
    let max = numArr.slice();
    for (let i = 0; i < numArr.length; i++) {
        for (let j = i + 1; j < numArr.length; j++) {
            numArr[i] = max[j];
            numArr[j] = max[i];
            let newNum = parseInt(numArr.join(''));
            if (newNum > num) {
                num = newNum;
            }
            numArr[j] = max[j];
            numArr[i] = max[i];
        }
    }
    return num;
};
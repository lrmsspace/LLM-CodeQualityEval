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
    let strNum = num.toString();
    let arr = strNum.split('').map(x => parseInt(x));
    let max = 0;
    let maxIndex = 0;
    let swapIndex = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
        if (arr[i] < max) {
            swapIndex = i;
        }
    }
    let temp = arr[maxIndex];
    arr[maxIndex] = arr[swapIndex];
    arr[swapIndex] = temp;
    return parseInt(arr.join(''));
};
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
    let nums = num.toString().split('');
    let max = nums.slice();
    let maxIndex = -1;
    let maxNum = -1;
    for(let i = nums.length - 1; i >= 0; i--){
        if(nums[i] > maxNum){
            maxNum = nums[i];
            maxIndex = i;
        }
        max[i] = maxNum;
    }
    for(let i = 0; i < nums.length; i++){
        if(nums[i] !== max[i]){
            let temp = nums[i];
            nums[i] = max[i];
           max[maxIndex] = temp;
        }
    }
    return parseInt(nums.join(''));

};
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
    // Convert number to string
    let numStr = num.toString();
    
    // Create an array to store the indices of digits
    let indices = Array.from({length: numStr.length}, (_, i) => i);
    
    // Sort the indices in descending order based on the digits
    indices.sort((a, b) => numStr[b] - numStr[a]);
    
    // Iterate through the sorted indices
    for (let i = 0; i < indices.length - 1; i++) {
        // Find the next digit greater than the current digit
        let j = indices.findIndex(index => numStr[index] > numStr[indices[i]]);
        
        // If a greater digit is found, swap the digits at the current and greater indices
        if (j!== -1) {
            [numStr[indices[i]], numStr[j]] = [numStr[j], numStr[indices[i]]];
            break;
        }
    }
    
    // Convert the string back to a number and return
    return parseInt(numStr);
    
};
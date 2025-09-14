/**https://leetcode.com/problems/split-with-minimum-sum/ */
//Given a positive integer num, split it into two non-negative integers num1 and num2 such that:
//	The concatenation of num1 and num2 is a permutation of num.
//	
//		In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the number of occurrences of that digit in num.
//	
//	
//	num1 and num2 can contain leading zeros.
//Return the minimum possible sum of num1 and num2.
//Notes:
//	It is guaranteed that num does not contain any leading zeros.
//	The order of occurrence of the digits in num1 and num2 may differ from the order of occurrence of num.
// 
//Example 1:
//Input: num = 4325
//Output: 59
//Explanation: We can split 4325 so that num1 is 24 and num2 is 35, giving a sum of 59. We can prove that 59 is indeed the minimal possible sum.
//Example 2:
//Input: num = 687
//Output: 75
//Explanation: We can split 687 so that num1 is 68 and num2 is 7, which would give an optimal sum of 75.
// 
//Constraints:
//	10 <= num <= 109
/**
 * @param {number} num
 * @return {number}
 */
var splitNum = function(num) {
    // Initialize a map to keep track of the frequency of digits in num
    let freqMap = new Map();
    let sum = 0;
    
    // Count the frequency of each digit in num
    while (num > 0) {
        let digit = num % 10;
        freqMap.set(digit, (freqMap.get(digit) || 0) + 1);
        sum += digit;
        num = Math.floor(num / 10);
    }
    
    // Iterate through the digits of num and find the smallest digit that can be split
    let minSplitSum = Infinity;
    let minSplitDigit = null;
    
    for (let [digit, count] of freqMap) {
        // If the count is odd, it means the digit can't be split into two equal parts
        if (count % 2 === 1) {
            let remainingCount = count - 1;
            let remainingSum = sum - digit;
            
            // Calculate the sum of the remaining digits
            let remainingSumDigits = 0;
            while (remainingCount > 0) {
                remainingSumDigits += remainingSum % 10;
                remainingSum = Math.floor(remainingSum / 10);
                remainingCount--;
            }
            
            // Calculate the sum of the minimum split
            let minSplit = Math.min(remainingSumDigits, remainingSum);
            
            // Update the minimum split sum and digit
            if (minSplit < minSplitSum) {
                minSplitSum = minSplit;
                minSplitDigit = digit;
            }
        }
    }
    
    // Return the minimum possible sum of num1 and num2
    return minSplitSum;
    
};
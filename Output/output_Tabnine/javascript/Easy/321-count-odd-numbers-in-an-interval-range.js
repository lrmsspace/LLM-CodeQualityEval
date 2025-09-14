/**https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/ */
//Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
// 
//Example 1:
//Input: low = 3, high = 7
//Output: 3
//Explanation: The odd numbers between 3 and 7 are [3,5,7].
//Example 2:
//Input: low = 8, high = 10
//Output: 1
//Explanation: The odd numbers between 8 and 10 are [9].
// 
//Constraints:
//	0 <= low <= high <= 10^9
/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var countOdds = function(low, high) {
    // If low is odd, increment low by 1 to make it even
    // If high is odd, decrement high by 1 to make it even
    if (low % 2 === 1) low++;
    if (high % 2 === 1) high--;
    
    // Calculate the range of even numbers between low and high
    // The range is (high - low + 1) / 2
    // Adding 1 to account for the inclusive high
    return Math.floor((high - low + 1) / 2) + 1;
    
};
/**https://leetcode.com/problems/lexicographical-numbers/ */
//Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
//You must write an algorithm that runs in O(n) time and uses O(1) extra space. 
// 
//Example 1:
//Input: n = 13
//Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
//Example 2:
//Input: n = 2
//Output: [1,2]
// 
//Constraints:
//	1 <= n <= 5 * 104
/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function(n) {
    const result =   []; // Initialize an empty array to store the result
    let curr = 1; // Start with the first number in lexicographical order
    while (result.length < n) { // Continue until we have n numbers in the result
        result.push(curr); // Add the current number to the result
        if (curr * 10 <= n) { // If multiplying by 10 is within bounds, go deeper
            curr *= 10; // Move to the next level in the lexicographical tree
        } else { // Otherwise, move to the next sibling
            if (curr >= n) { // If we are at the last number, go back up
                curr = Math.floor(curr / 10); // Go back to the parent node
                curr++; // Move to the next sibling
            } else { // If we are not at the last number, just increment
                curr++; // Move to the next number in lexicographical order
            }
        }
    }
    return result; // Return the result array containing numbers in lexicographical order 
};
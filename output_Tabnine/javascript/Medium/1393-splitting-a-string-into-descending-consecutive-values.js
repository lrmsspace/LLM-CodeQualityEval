/**https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/ */
//You are given a string s that consists of only digits.
//Check if we can split s into two or more non-empty substrings such that the numerical values of the substrings are in descending order and the difference between numerical values of every two adjacent substrings is equal to 1.
//	For example, the string s = "0090089" can be split into ["0090", "089"] with numerical values [90,89]. The values are in descending order and adjacent values differ by 1, so this way is valid.
//	Another example, the string s = "001" can be split into ["0", "01"], ["00", "1"], or ["0", "0", "1"]. However all the ways are invalid because they have numerical values [0,1], [0,1], and [0,0,1] respectively, all of which are not in descending order.
//Return true if it is possible to split s​​​​​​ as described above, or false otherwise.
//A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: s = "1234"
//Output: false
//Explanation: There is no valid way to split s.
//Example 2:
//Input: s = "050043"
//Output: true
//Explanation: s can be split into ["05", "004", "3"] with numerical values [5,4,3].
//The values are in descending order with adjacent values differing by 1.
//Example 3:
//Input: s = "9080701"
//Output: false
//Explanation: There is no valid way to split s.
// 
//Constraints:
//	1 <= s.length <= 20
//	s only consists of digits.
/**
 * @param {string} s
 * @return {boolean}
 */
var splitString = function(s) {
    // Check if the string has at least two digits
    if (s.length < 2) return false;
    
    // Convert the string to an array of digits
    const digits = Array.from(s, Number);
    
    // Initialize variables
    let i = 0;
    let j = 1;
    
    // Iterate through the digits array
    while (j < digits.length) {
        // Check if the current digit is less than the previous one
        if (digits[i] >= digits[j]) return false;
        
        // Check if the difference between the current and previous digits is not 1
        if (digits[j] - digits[i]!== 1) {
            // If the difference is not 1, reset the i and j pointers
            i = j;
        }
        
        // Move to the next pair of digits
        j++;
    }
    
    // If the loop completes without returning false, it means that the string can be split into descending consecutive values
    return true;
    
};
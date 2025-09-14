/*
 You are given a binary string s of length n and an integer numOps.
 You are allowed to perform the following operation on s at most numOps times:
 Select any index i (where 0 <= i < n) and flip s[i]. If s[i] == '1', change s[i] to '0' and vice versa.
 You need to minimize the length of the longest substring of s such that all the characters in the substring are identical.
 Return the minimum length after the operations.
 Example 1:
 Input: s = "000001", numOps = 1
 Output: 2
 Explanation: 
 By changing s[2] to '1', s becomes "001001". The longest substrings with identical characters are s[0..1] and s[3..4].
 Example 2:
 Input: s = "0000", numOps = 2
 Output: 1
 Explanation: 
 By changing s[0] and s[2] to '1', s becomes "1010".
 Example 3:
 Input: s = "0101", numOps = 0
 Output: 1
 Constraints:
 1 <= n == s.length <= 1000
 s consists only of '0' and '1'.
 0 <= numOps <= n
*/

/**
 * @param {string} s
 * @param {number} numOps
 * @return {number}
 */
var minLength = function(s, numOps) {
    // Initialize variables
    let minLength = s.length;
    let count = 0;
    let start = 0;
    
    // Iterate through the string
    for (let end = 0; end < s.length; end++) {
        // If the current character is different from the previous character, increment the count
        if (s[end]!== s[end - 1]) {
            count++;
        }
        
        // If the count exceeds the number of operations allowed, move the start pointer
        if (count > numOps) {
            while (s[start] === s[end]) {
                start++;
            }
            count--;
        }
        
        // Update the minimum length if necessary
        minLength = Math.min(minLength, end - start + 1);
    }
    
    return minLength;   
    
};
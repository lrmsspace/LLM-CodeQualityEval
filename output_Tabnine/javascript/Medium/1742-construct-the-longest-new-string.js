/**https://leetcode.com/problems/construct-the-longest-new-string/ */
//You are given three integers x, y, and z.
//You have x strings equal to "AA", y strings equal to "BB", and z strings equal to "AB". You want to choose some (possibly all or none) of these strings and concatenate them in some order to form a new string. This new string must not contain "AAA" or "BBB" as a substring.
//Return the maximum possible length of the new string.
//A substring is a contiguous non-empty sequence of characters within a string.
// 
//Example 1:
//Input: x = 2, y = 5, z = 1
//Output: 12
//Explanation: We can concactenate the strings "BB", "AA", "BB", "AA", "BB", and "AB" in that order. Then, our new string is "BBAABBAABBAB". 
//That string has length 12, and we can show that it is impossible to construct a string of longer length.
//Example 2:
//Input: x = 3, y = 2, z = 2
//Output: 14
//Explanation: We can concactenate the strings "AB", "AB", "AA", "BB", "AA", "BB", and "AA" in that order. Then, our new string is "ABABAABBAABBAA". 
//That string has length 14, and we can show that it is impossible to construct a string of longer length.
// 
//Constraints:
//	1 <= x, y, z <= 50
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {number}
 */
var longestString = function(x, y, z) {
    // Initialize the maximum length to 0
    let maxLength = 0;
    
    // Iterate over all possible combinations of x, y, and z
    for (let a = 0; a <= x; a++) {
        for (let b = 0; b <= y; b++) {
            for (let c = 0; c <= z; c++) {
                // Calculate the current length of the constructed string
                let currentLength = a * 2 + b * 3 + c * 4;
                
                // Check if the current length is greater than the maximum length
                if (currentLength > maxLength &&!hasSubstring(a, b, c)) {
                    maxLength = currentLength;
                }
            }
        }
    }
    
    // Return the maximum possible length of the new string
    return maxLength;
    
};
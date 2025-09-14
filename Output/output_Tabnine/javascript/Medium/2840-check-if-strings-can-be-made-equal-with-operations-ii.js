/*
 You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
 You can apply the following operation on any of the two strings any number of times:
 Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
 Return true if you can make the strings s1 and s2 equal, and false otherwise.
 Example 1:
 Input: s1 = "abcdba", s2 = "cabdab"
 Output: true
 Explanation: We can apply the following operations on s1:
 - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
 - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
 - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
 Example 2:
 Input: s1 = "abe", s2 = "bea"
 Output: false
 Explanation: It is not possible to make the two strings equal.
 Constraints:
 n == s1.length == s2.length
 1 <= n <= 105
 s1 and s2 consist only of lowercase English letters.
*/

/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkStrings = function(s1, s2) {

    // If the strings are not of equal length, return false
    if (s1.length!== s2.length) {
        return false;
    }
    
    // Create an array to store the indices of characters that need to be swapped
    const swapIndices = [];
    
    // Iterate through the strings and check if any character pairs can be swapped
    for (let i = 0; i < s1.length - 1; i++) {
        if (s1[i]!== s2[i]) {
            for (let j = i + 1; j < s1.length; j++) {
                if (s1[j] === s2[i] && (j - i) % 2 === 0) {
                    swapIndices.push([i, j]);
                    break;
                }
            }
        }
    }
    
    // If no character pairs need to be swapped, return true
    if (swapIndices.length === 0) {
        return true;
    }
    
    // Sort the swap indices based on the indices themselves
    swapIndices.sort((a, b) => a[0] - b[0]);
    
    // Iterate through the sorted swap indices and check if the swaps maintain the equal strings
    for (let i = 0; i < swapIndices.length - 1; i++) {
        if (s1.slice(0, swapIndices[i][0]) + s1.slice(swapIndices[i][1], s1.length)!==
            s2.slice(0, swapIndices[i][0]) + s2.slice(swapIndices[i][1], s2.length)) {
            return false;
        }
    }
    
    // If all swaps maintain the equal strings, return true
    return true;
    
};
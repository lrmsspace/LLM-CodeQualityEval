/**https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/ */
//Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.
//Return the maximum possible product of the lengths of the two palindromic subsequences.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.
// 
//Example 1:
//Input: s = "leetcodecom"
//Output: 9
//Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
//The product of their lengths is: 3 * 3 = 9.
//Example 2:
//Input: s = "bb"
//Output: 1
//Explanation: An optimal solution is to choose "b" (the first character) for the 1st subsequence and "b" (the second character) for the 2nd subsequence.
//The product of their lengths is: 1 * 1 = 1.
//Example 3:
//Input: s = "accbcaxxcxx"
//Output: 25
//Explanation: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
//The product of their lengths is: 5 * 5 = 25.
// 
//Constraints:
//	2 <= s.length <= 12
//	s consists of lowercase English letters only.
/**
 * @param {string} s
 * @return {number}
 */
var maxProduct = function(s) {
    // Create two arrays to store the lengths of the longest palindromic subsequences ending at each index
    const dp1 = new Array(s.length).fill(0);
    const dp2 = new Array(s.length).fill(0);
    
    // Initialize the lengths of the longest palindromic subsequences ending at the first and last indices
    dp1[0] = 1;
    dp2[s.length - 1] = 1;
    
    // Iterate from the second to the second-to-last index
    for (let i = 1; i < s.length - 1; i++) {
        // If the current character is equal to the previous character, update the lengths of the longest palindromic subsequences ending at the current index
        if (s[i] === s[i - 1]) {
            dp1[i] = dp1[i - 1] + 1;
            dp2[s.length - 1 - i] = dp2[s.length - i] + 1;
        }
    }
    
    // Iterate from the third to the last index
    for (let i = 2; i < s.length; i++) {
        // Iterate from the first to the second-to-last index
        for (let j = 0; j < s.length - i; j++) {
            // If the current subsequence is palindromic, update the lengths of the longest palindromic subsequences ending at the current index
            if (s[j] === s[j + i] && (i === 1 || s[j + 1] === s[j + i - 1])) {
                dp1[j + i] = Math.max(dp1[j + i], dp1[j] + 1);
                dp2[j + i] = Math.max(dp2[j + i], dp2[j + 1] + 1);
            }
        }
    }
    
    // Return the maximum possible product of the lengths of the two palindromic subsequences
    return Math.max(dp1[s.length - 1] * dp2[0], dp2[s.length - 1] * dp1[0]);
    
};
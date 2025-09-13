/**https://leetcode.com/problems/longest-palindrome/ */
//Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
//Letters are case sensitive, for example, "Aa" is not considered a palindrome.
// 
//Example 1:
//Input: s = "abccccdd"
//Output: 7
//Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
//Example 2:
//Input: s = "a"
//Output: 1
//Explanation: The longest palindrome that can be built is "a", whose length is 1.
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase and/or uppercase English letters only.
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let count = Array(26).fill(0); // Counts the frequency of each character
    let oddCount = 0; // Counts the number of characters with odd frequency
    
    for (let char of s) {
        count[char.charCodeAt() - 'a'.charCodeAt()]++;
    }
    
    for (let freq of count) {
        oddCount += freq % 2;
    }
    
    return s.length - oddCount + (oddCount > 0); // Add one to account for the middle character(s)
    
};
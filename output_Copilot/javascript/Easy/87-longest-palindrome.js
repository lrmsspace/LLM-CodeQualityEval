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
    let count = 0;
    let oddCount = 0;
    const charCount = {};
    
    for (let i = 0; i < s.length; i++) {
        charCount[s[i]] = (charCount[s[i]] || 0) + 1;
    }
    
    for (const key in charCount) {
        if (charCount[key] % 2 === 0) {
            count += charCount[key];
        } else {
            count += charCount[key] - 1;
            oddCount = 1;
        }
    }
    
    return count + oddCount;    
};
/**https://leetcode.com/problems/longest-palindromic-substring/ */
//Given a string s, return the longest palindromic substring in s.
// 
//Example 1:
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
//Example 2:
//Input: s = "cbbd"
//Output: "bb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consist of only digits and English letters.
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let max = 0;
    let maxStr = '';
    for(let i=0; i<s.length; i++){
        for(let j=i+1; j<=s.length; j++){
            let str = s.slice(i,j);
            if(str.length > max && isPalindrome(str)){
                max = str.length;
                maxStr = str;
            }
        }
    }
    return maxStr;
 
};
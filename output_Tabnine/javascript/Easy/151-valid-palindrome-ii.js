/**https://leetcode.com/problems/valid-palindrome-ii/ */
//Given a string s, return true if the s can be palindrome after deleting at most one character from it.
// 
//Example 1:
//Input: s = "aba"
//Output: true
//Example 2:
//Input: s = "abca"
//Output: true
//Explanation: You could delete the character 'c'.
//Example 3:
//Input: s = "abc"
//Output: false
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
    const isPalindrome = (left, right) => {
        while (left < right) {
            if (s[left]!== s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    };
    
    for (let i = 0; i < s.length - 1; i++) {
        if (s[i] === s[i + 1]) {
            return isPalindrome(i, i + 1) || isPalindrome(i, s.length - 1);
        }
    }
    
    return true;
    
};
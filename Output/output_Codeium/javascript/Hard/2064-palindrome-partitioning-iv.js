/**https://leetcode.com/problems/palindrome-partitioning-iv/ */
//Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​
//A string is said to be palindrome if it the same string when reversed.
// 
//Example 1:
//Input: s = "abcbdd"
//Output: true
//Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
//Example 2:
//Input: s = "bcbddxy"
//Output: false
//Explanation: s cannot be split into 3 palindromes.
// 
//Constraints:
//	3 <= s.length <= 2000
//	s​​​​​​ consists only of lowercase English letters.
/**
 * @param {string} s
 * @return {boolean}
 */
var checkPartitioning = function(s) {
    for (let i = 0; i < s.length - 2; i++) {
        for (let j = i + 1; j < s.length - 1; j++) {
            let first = s.substring(0, i + 1);
            let second = s.substring(i + 1, j + 1);
            let third = s.substring(j + 1);
            if (isPalindrome(first) && isPalindrome(second) && isPalindrome(third)) {
                return true;
            }
        }
    }
    return false;

    function isPalindrome(str) {
        let left = 0, right = str.length - 1;
        while (left < right) {
            if (str[left] !== str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
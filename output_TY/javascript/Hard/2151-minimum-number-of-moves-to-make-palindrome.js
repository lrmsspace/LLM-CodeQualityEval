/**https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/ */
//You are given a string s consisting only of lowercase English letters.
//In one move, you can select any two adjacent characters of s and swap them.
//Return the minimum number of moves needed to make s a palindrome.
//Note that the input will be generated such that s can always be converted to a palindrome.
// 
//Example 1:
//Input: s = "aabb"
//Output: 2
//Explanation:
//We can obtain two palindromes from s, "abba" and "baab". 
//- We can obtain "abba" from s in 2 moves: "aabb" -> "abab" -> "abba".
//- We can obtain "baab" from s in 2 moves: "aabb" -> "abab" -> "baab".
//Thus, the minimum number of moves needed to make s a palindrome is 2.
//Example 2:
//Input: s = "letelt"
//Output: 2
//Explanation:
//One of the palindromes we can obtain from s in 2 moves is "lettel".
//One of the ways we can obtain it is "letelt" -> "letetl" -> "lettel".
//Other palindromes such as "tleelt" can also be obtained in 2 moves.
//It can be shown that it is not possible to obtain a palindrome in less than 2 moves.
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists only of lowercase English letters.
//	s can be converted to a palindrome using a finite number of moves.
/**
 * @param {string} s
 * @return {number}
 */
var minMovesToMakePalindrome = function(s) {
    let count = 0;
    let left = 0;
    let right = s.length - 1;
    while (left < right) {
        let leftChar = s[left];
        let rightChar = s[right];
        if (leftChar !== rightChar) {
            let leftIndex = s.indexOf(rightChar, left + 1);
            if (leftIndex !== -1) {
                count += leftIndex - left;
                s = s.slice(0, left) + s[leftIndex] + s.slice(left + 1, leftIndex) + s[left] + s.slice(leftIndex + 1);
            } else {
                count += right - left;
            }
        }
    }
    return count;
};
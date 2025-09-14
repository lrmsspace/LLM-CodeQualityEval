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
    let moves = 0;
    let left = 0;
    let right = s.length - 1;
    while (left < right) {
        if (s[left] === s[right]) {
            left++;
            right--;
        } else {
            let l = left;
            let r = right;
            while (l < r && s[l] !== s[right]) {
                l++;
            }
            if (l === r) {
                moves += 1;
                left++;
                right--;
            } else {
                moves += r - l;
                for (let i = l; i < r; i++) {
                    [s[i], s[i + 1]] = [s[i + 1], s[i]];
                }
                left++;
                right--;
            }
        }
    }
    return moves;    
};
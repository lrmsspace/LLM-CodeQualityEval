/**https://leetcode.com/problems/super-palindromes/ */
//Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
//Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].
// 
//Example 1:
//Input: left = "4", right = "1000"
//Output: 4
//Explanation: 4, 9, 121, and 484 are superpalindromes.
//Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
//Example 2:
//Input: left = "1", right = "2"
//Output: 1
// 
//Constraints:
//	1 <= left.length, right.length <= 18
//	left and right consist of only digits.
//	left and right cannot have leading zeros.
//	left and right represent integers in the range [1, 1018 - 1].
//	left is less than or equal to right.
/**
 * @param {string} left
 * @param {string} right
 * @return {number}
 */
var superpalindromesInRange = function(left, right) {
    let count = 0;
    let i = 1;
    while(true){
        let palindrome = i.toString();
        let j = palindrome.length - 1;
        while(j >= 0){
            palindrome += palindrome[j];
            j--;
        }
        let square = BigInt(palindrome) * BigInt(palindrome);
        if(square.toString() === square.toString().split("").reverse().join("")){
            if(square >= left && square <= right){
                count++;
            }
        }
        i++;
        if(square > right){
            break;
        }
    }
    return count;
};
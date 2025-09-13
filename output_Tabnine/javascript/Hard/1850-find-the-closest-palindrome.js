/**https://leetcode.com/problems/find-the-closest-palindrome/ */
//Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
//The closest is defined as the absolute difference minimized between two integers.
// 
//Example 1:
//Input: n = "123"
//Output: "121"
//Example 2:
//Input: n = "1"
//Output: "0"
//Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
// 
//Constraints:
//	1 <= n.length <= 18
//	n consists of only digits.
//	n does not have leading zeros.
//	n is representing an integer in the range [1, 1018 - 1].
/**
 * @param {string} n
 * @return {string}
 */
var nearestPalindromic = function(n) {
    const isPalindrome = num => {
        const str = num.toString();
        let left = 0;
        let right = str.length - 1;
        while (left < right) {
            if (str[left]!== str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    };
    
    const findClosestPalindrome = num => {
        let left = parseInt(num);
        let right = left + 1;
        
        while (!isPalindrome(left.toString())) {
            left--;
        }
        
        while (!isPalindrome(right.toString())) {
            right++;
        }
        
        const diffLeft = Math.abs(left - parseInt(num));
        const diffRight = Math.abs(right - parseInt(num));
        
        return diffLeft <= diffRight? left.toString() : right.toString();
    };
    
    return findClosestPalindrome(n);
    
};
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
    const len = n.length;
    const candidates = new Set();
    const prefix = n.slice(0, Math.ceil(len / 2));
    
    // Generate candidates based on the prefix
    for (let i = -1; i <= 1; i++) {
        const newPrefix = BigInt(prefix) + BigInt(i);
        const newPalin = newPrefix.toString() + newPrefix.toString().split('').reverse().join('');
        candidates.add(newPalin);
    }
    
    // Add edge cases
    candidates.add('9'.repeat(len - 1));
    candidates.add('1' + '0'.repeat(len - 1));
    
    // Remove the original number and find the closest palindrome
    candidates.delete(n);
    
    let closest = '';
    let minDiff = Infinity;
    
    for (const candidate of candidates) {
        const diff = Math.abs(BigInt(candidate) - BigInt(n));
        if (diff < minDiff || (diff === minDiff && candidate < closest)) {
            minDiff = diff;
            closest = candidate;
        }
    }
    
    return closest;    
};
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
    let len = n.length;
    let candidates = new Set([Math.pow(10, len - 1) - 1, Math.pow(10, len) + 1]);
    let prefix = parseInt(n.substring(0, (len + 1) / 2));
    for (let i = prefix - 1; i <= prefix + 1; i++) {
        let s = i.toString();
        let candidate = (len & 1) == 0 ? s + s.reverse() : s + s.reverse().substring(1);
        candidates.add(parseInt(candidate));
    }
    let minDiff = Number.MAX_VALUE;
    let result = 0;
    candidates.forEach(candidate => {
        if (candidate != parseInt(n)) {
            let diff = Math.abs(candidate - parseInt(n));
            if (diff < minDiff) {
                minDiff = diff;
                result = candidate;
            } else if (diff == minDiff) {
                result = Math.min(result, candidate);
            }
        }
    });
    return result.toString();
};
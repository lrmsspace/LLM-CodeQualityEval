/**https://leetcode.com/problems/find-longest-awesome-substring/ */
//You are given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it a palindrome.
//Return the length of the maximum length awesome substring of s.
// 
//Example 1:
//Input: s = "3242415"
//Output: 5
//Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
//Example 2:
//Input: s = "12345678"
//Output: 1
//Example 3:
//Input: s = "213123"
//Output: 6
//Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists only of digits.
/**
 * @param {string} s
 * @return {number}
 */
var longestAwesome = function(s) {
    let n = s.length;
    const dp = new Array(n).fill(0);
    const freq = new Map();
    let ans = 0;
    freq.set(0, -1);
    
    for (let i = 0; i < n; i++) {
        const num = parseInt(s[i]);
        const bitmask = (1 << num) - 1;
        
        for (let j = 0; j < 31; j++) {
            const xor = bitmask ^ (1 << j);
            if (freq.has(xor)) {
                ans = Math.max(ans, i - freq.get(xor));
            }
        }
        
        freq.set(bitmask, i);
    }
    
    return ans;
    
};
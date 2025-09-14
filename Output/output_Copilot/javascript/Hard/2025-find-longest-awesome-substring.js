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
    let ans = 0;
    let mask = 0;
    let map = new Map();
    map.set(0, -1);
    
    for (let i = 0; i < n; i++) {
        mask ^= 1 << (s[i] - '0');
        if (map.has(mask)) {
            ans = Math.max(ans, i - map.get(mask));
        } else {
            map.set(mask, i);
        }
        
        for (let j = 0; j < 10; j++) {
            let newMask = mask ^ (1 << j);
            if (map.has(newMask)) {
                ans = Math.max(ans, i - map.get(newMask));
            }
        }
    }
    
    return ans;    
};
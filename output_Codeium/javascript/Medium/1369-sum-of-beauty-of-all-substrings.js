/**https://leetcode.com/problems/sum-of-beauty-of-all-substrings/ */
//The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
//	For example, the beauty of "abaacc" is 3 - 1 = 2.
//Given a string s, return the sum of beauty of all of its substrings.
// 
//Example 1:
//Input: s = "aabcb"
//Output: 5
//Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
//Example 2:
//Input: s = "aabcbaa"
//Output: 17
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters.
/**
 * @param {string} s
 * @return {number}
 */
var beautySum = function(s) {
    let res = 0;
    for (let i = 0; i < s.length; i++) {
        const freq = {};
        for (let j = i; j < s.length; j++) {
            freq[s[j]] = (freq[s[j]] || 0) + 1;
            const max = Math.max(...Object.values(freq));
            const min = Math.min(...Object.values(freq));
            res += max - min;
        }
    }
    return res;
    
};
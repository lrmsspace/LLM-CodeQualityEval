/**https://leetcode.com/problems/check-if-a-string-can-break-another-string/ */
//Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa. In other words s2 can break s1 or vice-versa.
//A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.
// 
//Example 1:
//Input: s1 = "abc", s2 = "xya"
//Output: true
//Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".
//Example 2:
//Input: s1 = "abe", s2 = "acd"
//Output: false 
//Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.
//Example 3:
//Input: s1 = "leetcodee", s2 = "interview"
//Output: true
// 
//Constraints:
//	s1.length == n
//	s2.length == n
//	1 <= n <= 10^5
//	All strings consist of lowercase English letters.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkIfCanBreak = function(s1, s2) {
    let freq1 = new Array(26).fill(0);
    let freq2 = new Array(26).fill(0);
    
    for (let i = 0; i < s1.length; i++) {
        freq1[s1[i].charCodeAt() - 97]++;
        freq2[s2[i].charCodeAt() - 97]++;
    }
    
    let max1 = freq1[0];
    let min1 = freq1[0];
    
    for (let i = 1; i < 26; i++) {
        max1 = Math.max(max1, freq1[i]);
        min1 = Math.min(min1, freq1[i]);
    }
    
    let max2 = freq2[0];
    let min2 = freq2[0];
    
    for (let i = 1; i < 26; i++) {
        max2 = Math.max(max2, freq2[i]);
        min2 = Math.min(min2, freq2[i]);
    }
    
    return (max1 <= min2) && (max2 <= min1);
    
};
/**https://leetcode.com/problems/shortest-palindrome/ */
//You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//Return the shortest palindrome you can find by performing this transformation.
// 
//Example 1:
//Input: s = "aacecaaa"
//Output: "aaacecaaa"
//Example 2:
//Input: s = "abcd"
//Output: "dcbabcd"
// 
//Constraints:
//	0 <= s.length <= 5 * 104
//	s consists of lowercase English letters only.
/**
 * @param {string} s
 * @return {string}
 */
var shortestPalindrome = function(s) {
    let n = s.length;
    let j = 0;
    let p = new Array(n).fill(0);
    
    for (let i = 1; i < n; i++) {
        if (j > i - p[j]) {
            p[i] = Math.min(j + p[j] - i, p[2 * j - i]);
        }
        
        while (i + p[i] < n && i - p[i] - 1 >= 0 && s[i + p[i]] === s[i - p[i] - 1]) {
            p[i]++;
        }
        
        if (i + p[i] > j + p[j]) {
            j = i;
        }
    }
    
    let rev = s.slice(0, j).split('').reverse().join('');
    return rev + s;
    
};
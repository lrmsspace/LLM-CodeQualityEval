/**https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/ */
//You are given a string s (0-indexed)​​​​​​. You are asked to perform the following operation on s​​​​​​ until you get a sorted string:
//	Find the largest index i such that 1 <= i < s.length and s[i] < s[i - 1].
//	Find the largest index j such that i <= j < s.length and s[k] < s[i - 1] for all the possible values of k in the range [i, j] inclusive.
//	Swap the two characters at indices i - 1​​​​ and j​​​​​.
//	Reverse the suffix starting at index i​​​​​​.
//Return the number of operations needed to make the string sorted. Since the answer can be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: s = "cba"
//Output: 5
//Explanation: The simulation goes as follows:
//Operation 1: i=2, j=2. Swap s[1] and s[2] to get s="cab", then reverse the suffix starting at 2. Now, s="cab".
//Operation 2: i=1, j=2. Swap s[0] and s[2] to get s="bac", then reverse the suffix starting at 1. Now, s="bca".
//Operation 3: i=2, j=2. Swap s[1] and s[2] to get s="bac", then reverse the suffix starting at 2. Now, s="bac".
//Operation 4: i=1, j=1. Swap s[0] and s[1] to get s="abc", then reverse the suffix starting at 1. Now, s="acb".
//Operation 5: i=2, j=2. Swap s[1] and s[2] to get s="abc", then reverse the suffix starting at 2. Now, s="abc".
//Example 2:
//Input: s = "aabaa"
//Output: 2
//Explanation: The simulation goes as follows:
//Operation 1: i=3, j=4. Swap s[2] and s[4] to get s="aaaab", then reverse the substring starting at 3. Now, s="aaaba".
//Operation 2: i=4, j=4. Swap s[3] and s[4] to get s="aaaab", then reverse the substring starting at 4. Now, s="aaaab".
// 
//Constraints:
//	1 <= s.length <= 3000
//	s​​​​​​ consists only of lowercase English letters.
/**
 * @param {string} s
 * @return {number}
 */
var makeStringSorted = function(s) {
    let n = s.length;
    let MOD = 1000000007;
    let fact = new Array(n + 1).fill(0);
    fact[0] = 1;
    for (let i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    let count = new Array(26).fill(0);
    for (let i = 0; i < n; i++) {
        count[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }
    let ans = 0;
    for (let i = 0; i < n; i++) {
        let less = 0;
        for (let j = 0; j < s.charCodeAt(i) - 'a'.charCodeAt(0); j++) {
            less += count[j];
        }
        ans = (ans + less * fact[n - i - 1]) % MOD;
        for (let j = 0; j < 26; j++) {
            ans = (ans + count[j] * fact[n - i - 1]) % MOD;
        }
        count[s.charCodeAt(i) - 'a'.charCodeAt(0)]--;
    }
    return ans; 
};
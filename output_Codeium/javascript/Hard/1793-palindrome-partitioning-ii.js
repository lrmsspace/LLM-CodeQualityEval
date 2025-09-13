/**https://leetcode.com/problems/palindrome-partitioning-ii/ */
//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return the minimum cuts needed for a palindrome partitioning of s.
// 
//Example 1:
//Input: s = "aab"
//Output: 1
//Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//Example 2:
//Input: s = "a"
//Output: 0
//Example 3:
//Input: s = "ab"
//Output: 1
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase English letters only.
/**
 * @param {string} s
 * @return {number}
 */
var minCut = function(s) {
const n = s.length;
const isPalindrome = Array.from({ length: n }, () => Array(n).fill(false));
const minCuts = Array(n).fill(0);

for (let end = 0; end < n; end++) {
    minCuts[end] = end; // Maximum cuts
    for (let start = 0; start <= end; start++) {
        if (s[start] === s[end] && (end - start <= 2 || isPalindrome[start + 1][end - 1])) {
            isPalindrome[start][end] = true;
            minCuts[end] = start === 0 ? 0 : Math.min(minCuts[end], minCuts[start - 1] + 1);
        }
    }
}

return minCuts[n - 1];

};
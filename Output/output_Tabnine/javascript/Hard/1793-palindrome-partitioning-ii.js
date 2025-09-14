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
    const dp = Array(n+1).fill(0).map(() => Array(n).fill(false));
    const palindrome = Array(n).fill(true);
    let minCuts = Array(n+1).fill(0);
    
    for(let i = n-1; i >= 0; i--){
        for(let j = i+1; j <= n; j++){
            if(s[i] === s[j-1] && (j-i <= 2 || palindrome[i+1][j-1])){
                palindrome[i][j-1] = true;
            }
        }
    }
    
    for(let i = 1; i <= n; i++){
        minCuts[i] = i-1;
        for(let j = 0; j < i; j++){
            if(palindrome[j+1][i]){
                minCuts[i] = Math.min(minCuts[i], minCuts[j]+1);
            }
        }
    }
    
    return minCuts[n];
    
};
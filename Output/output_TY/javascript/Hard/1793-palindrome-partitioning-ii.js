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
    let n = s.length;
    let dp = new Array(n).fill(0).map(() => new Array(n).fill(false));
    for(let i=0;i<n;i++){
        dp[i][i] = true;
    }
    for(let i=n-1;i>=0;i--){
        for(let j=i+1;j<n;j++){
            if(s[i]===s[j]){
                dp[i][j] = dp[i+1][j-1];
            }
        }
    }
    let cut = new Array(n).fill(0);
    for(let i=1;i<n;i++){
        if(dp[0][i]){
            cut[i] = 0;
        }else{
            cut[i] = Number.MAX_SAFE_INTEGER;
            for(let j=0;j<i;j++){
                if(dp[j+1][i]){
                    cut[i] = Math.min(cut[i],cut[j]+1);
                }
            }
        }
    }
        return cut[n-1];
};
/**https://leetcode.com/problems/count-vowels-permutation/ */
//Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
//	Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
//	Each vowel 'a' may only be followed by an 'e'.
//	Each vowel 'e' may only be followed by an 'a' or an 'i'.
//	Each vowel 'i' may not be followed by another 'i'.
//	Each vowel 'o' may only be followed by an 'i' or a 'u'.
//	Each vowel 'u' may only be followed by an 'a'.
//Since the answer may be too large, return it modulo 10^9 + 7.
// 
//Example 1:
//Input: n = 1
//Output: 5
//Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
//Example 2:
//Input: n = 2
//Output: 10
//Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
//Example 3: 
//Input: n = 5
//Output: 68
// 
//Constraints:
//	1 <= n <= 2 * 10^4
class Solution {
    public int countVowelPermutation(int n) {
        int MOD = 1000000007;
        long[][] dp = new long[n+1][5];
        for(int i=0;i<5;i++) dp[1][i] = 1;
        long[][] relation = {{0,2},{0,4},{1,3},{2,1},{3,0},{4,2}};
        for(int i=1;i<n;i++){
            for(int j=0;j<5;j++){
                dp[i+1][j] = 0;
                for(int k=0;k<6;k++){
                    dp[i+1][j] += dp[i][relation[k][0]] * dp[i][relation[k]][relation[k][1]];
                }
            }
        }
        return (int)(dp[n][0]%mod);  
    }
}
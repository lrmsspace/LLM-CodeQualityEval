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

        int MOD = (int) 1e9 + 7;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        int[] prev = new int[5];
        Arrays.fill(prev, 1);
        
        for (int i = 1; i <= n; i++) {
            int[] temp = Arrays.copyOf(prev, 5);
            prev[0] = temp[1] + temp[2] + temp[4];
            prev[1] = temp[0] + temp[2];
            prev[2] = temp[1] + temp[3];
            prev[3] = temp[2];
            prev[4] = temp[2] + temp[3];
            for (int j = 0; j < 5; j++) {
                dp[i] = (dp[i] + prev[j]) % MOD;
            }
        }
        
        return dp[n];
    }
}
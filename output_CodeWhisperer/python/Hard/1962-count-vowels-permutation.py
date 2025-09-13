#https://leetcode.com/problems/count-vowels-permutation/
#Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
#	Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
#	Each vowel 'a' may only be followed by an 'e'.
#	Each vowel 'e' may only be followed by an 'a' or an 'i'.
#	Each vowel 'i' may not be followed by another 'i'.
#	Each vowel 'o' may only be followed by an 'i' or a 'u'.
#	Each vowel 'u' may only be followed by an 'a'.
#Since the answer may be too large, return it modulo 10^9 + 7.
# 
#Example 1:
#Input: n = 1
#Output: 5
#Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
#Example 2:
#Input: n = 2
#Output: 10
#Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
#Example 3: 
#Input: n = 5
#Output: 68
# 
#Constraints:
#	1 <= n <= 2 * 10^4
class Solution(object):
    def countVowelPermutation(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9 + 7
        
        # Initialize dp array for each vowel
        # dp[i][j] represents count of strings of length i+1 ending with vowel j
        # j: 0=a, 1=e, 2=i, 3=o, 4=u
        dp = [[0] * 5 for _ in range(n)]    
        
        # Base case: strings of length 1
        for j in range(5):
            dp[0][j] = 1
        
        # Rules for vowel transitions:
        # a -> e
        # e -> a, i
        # i -> a, e, o, u
        # o -> i, u
        # u -> a
        
        for i in range(1, n):
            # Count strings ending in 'a'
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4]) % MOD
            
            # Count strings ending in 'e'
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD
            
            # Count strings ending in 'i'
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % MOD
            
            # Count strings ending in 'o'
            dp[i][3] = dp[i-1][2] % MOD
            
            # Count strings ending in 'u'
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % MOD
        
        # Sum up all possibilities for strings of length n
        return sum(dp[n-1]) % MOD

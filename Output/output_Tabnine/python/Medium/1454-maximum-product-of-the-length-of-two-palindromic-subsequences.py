#https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
#Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.
#Return the maximum possible product of the lengths of the two palindromic subsequences.
#A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.
# 
#Example 1:
#Input: s = "leetcodecom"
#Output: 9
#Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
#The product of their lengths is: 3 * 3 = 9.
#Example 2:
#Input: s = "bb"
#Output: 1
#Explanation: An optimal solution is to choose "b" (the first character) for the 1st subsequence and "b" (the second character) for the 2nd subsequence.
#The product of their lengths is: 1 * 1 = 1.
#Example 3:
#Input: s = "accbcaxxcxx"
#Output: 25
#Explanation: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
#The product of their lengths is: 5 * 5 = 25.
# 
#Constraints:
#	2 <= s.length <= 12
#	s consists of lowercase English letters only.
class Solution(object):
    def maxProduct(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Create two dp arrays, one for each palindromic subsequence
        dp1 = [0] * len(s)
        dp2 = [0] * len(s)
        
        # Initialize the first palindromic subsequence
        for i in range(len(s)):
            dp1[i] = 1
            if i > 0 and s[i] == s[i-1]:
                dp1[i] = dp1[i-2] + 2
        
        # Initialize the second palindromic subsequence
        for i in range(len(s)-2, -1, -1):
            dp2[i] = 1
            if i < len(s)-1 and s[i] == s[i+1]:
                dp2[i] = dp2[i+2] + 2
        
        # Find the maximum product of the lengths of the two palindromic subsequences
        max_product = 0
        for i in range(len(s)):
            for j in range(i+1, len(s)):
                max_product = max(max_product, dp1[i] * dp2[j])
        
        return max_product
        
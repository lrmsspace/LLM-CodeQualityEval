#https://leetcode.com/problems/palindrome-partitioning-iii/
#You are given a string s containing lowercase letters and an integer k. You need to :
#	First, change some characters of s to other lowercase English letters.
#	Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.
#Return the minimal number of characters that you need to change to divide the string.
# 
#Example 1:
#Input: s = "abc", k = 2
#Output: 1
#Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
#Example 2:
#Input: s = "aabbc", k = 3
#Output: 0
#Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.
#Example 3:
#Input: s = "leetcode", k = 8
#Output: 0
# 
#Constraints:
#	1 <= k <= s.length <= 100.
#	s only contains lowercase English letters.
class Solution(object):
    def palindromePartition(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        # Create a list to store the minimum number of changes needed to make each substring a palindrome
        dp = [float('inf')] * (len(s) + 1)
        dp[0] = 0
        
        # Create a list to store the last index of each substring
        last = [0] * (len(s) + 1)
        
        # Iterate through the string from left to right
        for i in range(1, len(s) + 1):
            # Iterate through the possible length of each substring
            for j in range(1, i + 1):
                # Check if the substring is a palindrome
                if s[i - j:i] == s[i - j:i][::-1]:
                    # Update the minimum number of changes needed to make the substring a palindrome
                    dp[i] = min(dp[i], dp[i - j] + (last[i - j] - j + 1) * (last[i - j] - j + 1))
        
        # Return the minimum number of changes needed to divide the string
        return dp[-1]
        
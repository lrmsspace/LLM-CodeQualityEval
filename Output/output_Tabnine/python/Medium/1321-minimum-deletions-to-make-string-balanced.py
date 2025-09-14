#https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
#You are given a string s consisting only of characters 'a' and 'b'​​​​.
#You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
#Return the minimum number of deletions needed to make s balanced.
# 
#Example 1:
#Input: s = "aababbab"
#Output: 2
#Explanation: You can either:
#Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
#Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
#Example 2:
#Input: s = "bbaaaaabb"
#Output: 2
#Explanation: The only solution is to delete the first two characters.
# 
#Constraints:
#	1 <= s.length <= 105
#	s[i] is 'a' or 'b'​​.
class Solution(object):
    def minimumDeletions(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize variables
        balanced = True
        deletions = 0
        left, right = 0, len(s) - 1
        
        # Iterate until the left pointer is less than the right pointer
        while left < right:
            # If the characters at the left and right pointers are different, increment the deletions counter
            if s[left]!= s[right]:
                deletions += 1
            # Move the pointers towards the center
            left += 1
            right -= 1
        
        # If the string is not balanced, return the number of deletions
        if not balanced:
            return deletions
        
        # If the string is balanced, check if there are any pairs of consecutive 'a' characters
        for i in range(len(s) - 1):
            if s[i] == 'a' and s[i + 1] == 'a':
                return deletions + 1
        
        # If there are no pairs of consecutive 'a' characters, return 0

        
        
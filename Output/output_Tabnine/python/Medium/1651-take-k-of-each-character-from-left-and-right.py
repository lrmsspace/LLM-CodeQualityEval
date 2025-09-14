#https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
#You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
#Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.
# 
#Example 1:
#Input: s = "aabaaaacaabc", k = 2
#Output: 8
#Explanation: 
#Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
#Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
#A total of 3 + 5 = 8 minutes is needed.
#It can be proven that 8 is the minimum number of minutes needed.
#Example 2:
#Input: s = "a", k = 1
#Output: -1
#Explanation: It is not possible to take one 'b' or 'c' so return -1.
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of only the letters 'a', 'b', and 'c'.
#	0 <= k <= s.length
class Solution(object):
    def takeCharacters(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        # Initialize counters for 'a', 'b', and 'c'
        a_count = 0
        b_count = 0
        c_count = 0
        
        # Initialize the left and right pointers
        left = 0
        right = len(s) - 1
        
        # Iterate through the string
        while left <= right:
            # If the character is 'a', increment the 'a' counter
            if s[left] == 'a':
                a_count += 1
            # If the character is 'b', increment the 'b' counter
            elif s[left] == 'b':
                b_count += 1
            # If the character is 'c', increment the 'c' counter
            elif s[left] == 'c':
                c_count += 1
            
            # If the 'a' counter is less than or equal to k, move the left pointer
            if a_count <= k:
                left += 1
                continue
            # If the 'b' counter is less than or equal to k, move the left pointer
            if b_count <= k:
                left += 1
                continue
            # If the 'c' counter is less than or equal to k, move the left pointer
            if c_count <= k:
                left += 1
                continue
            
            # If we reach this point, it means we cannot take k of each character
            return -1
        
        # Calculate the total number of minutes needed
        return right - left + 1
        
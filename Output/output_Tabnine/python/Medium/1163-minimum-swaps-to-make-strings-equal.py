#https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/
#You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].
#Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.
# 
#Example 1:
#Input: s1 = "xx", s2 = "yy"
#Output: 1
#Explanation: Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
#Example 2:
#Input: s1 = "xy", s2 = "yx"
#Output: 2
#Explanation: Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
#Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
#Note that you cannot swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
#Example 3:
#Input: s1 = "xx", s2 = "xy"
#Output: -1
# 
#Constraints:
#	1 <= s1.length, s2.length <= 1000
#	s1.length == s2.length
#	s1, s2 only contain 'x' or 'y'.
class Solution(object):
    def minimumSwap(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        # Count the number of 'x' and 'y' in both strings
        x_count, y_count = s1.count('x'), s1.count('y')
        
        # If the number of 'x' and 'y' is not equal, it is impossible to make s1 and s2 equal
        if x_count!= y_count:
            return -1
        
        # Initialize the minimum number of swaps
        min_swaps = 0
        
        # Initialize two pointers, i and j, to iterate through the strings
        i, j = 0, 0
        
        # Iterate until i reaches the end of s1
        while i < len(s1):
            # If s1[i] is 'x' and s2[j] is 'y', swap them
            if s1[i] == 'x' and s2[j] == 'y':
                min_swaps += 1
                i += 1
                j += 1
            # If s1[i] is 'y' and s2[j] is 'x', increment j
            elif s1[i] == 'y' and s2[j] == 'x':
                j += 1
            # If s1[i] is 'x' and s2[j] is 'x', increment i
            elif s1[i] == 'x' and s2[j] == 'x':
                i += 1
        
        # Return the minimum number of swaps
        return min_swaps
        
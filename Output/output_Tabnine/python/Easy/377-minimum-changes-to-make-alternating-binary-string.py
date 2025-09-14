#https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
#You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.
#The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.
#Return the minimum number of operations needed to make s alternating.
# 
#Example 1:
#Input: s = "0100"
#Output: 1
#Explanation: If you change the last character to '1', s will be "0101", which is alternating.
#Example 2:
#Input: s = "10"
#Output: 0
#Explanation: s is already alternating.
#Example 3:
#Input: s = "1111"
#Output: 2
#Explanation: You need two operations to reach "0101" or "1010".
# 
#Constraints:
#	1 <= s.length <= 104
#	s[i] is either '0' or '1'.
class Solution(object):
    def minOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize the count of operations and the previous character
        count, prev = 0, s[0]
        
        # Iterate through the string starting from the second character
        for c in s[1:]:
            # If the current character is not equal to the previous character, increment the count
            if c!= prev:
                count += 1
            # Update the previous character
            prev = c
        
        # Return the minimum number of operations
        return count
        
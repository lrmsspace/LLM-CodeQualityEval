#https://leetcode.com/problems/additive-number/
#An additive number is a string whose digits can form an additive sequence.
#A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
#Given a string containing only digits, return true if it is an additive number or false otherwise.
#Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
# 
#Example 1:
#Input: "112358"
#Output: true
#Explanation: 
#The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
#1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
#Example 2:
#Input: "199100199"
#Output: true
#Explanation: 
#The additive sequence is: 1, 99, 100, 199. 
#1 + 99 = 100, 99 + 100 = 199
# 
#Constraints:
#	1 <= num.length <= 35
#	num consists only of digits.
# 
#Follow up: How would you handle overflow for very large input integers?
class Solution(object):
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        # Edge case: empty string or single digit string
        if len(num) < 3:
            return False
        
        # Initialize the first two numbers and the length of the additive sequence
        first, second = int(num[0]), int(num[1])
        length = 2
        
        # Check if the sequence is valid
        while length < len(num):
            # Calculate the next number in the sequence
            next_num = first + second
            next_num_str = str(next_num)
            
            # Check if the next number can be formed by concatenating the last two numbers
            if num[length:length+len(next_num_str)]!= next_num_str:
                break
            
            # Update the first two numbers and the length
            first, second = second, next_num
            length += len(next_num_str)
        
        # Return True if the sequence is valid, False otherwise
        return length == len(num)
        
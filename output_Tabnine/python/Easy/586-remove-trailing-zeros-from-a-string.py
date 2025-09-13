#https://leetcode.com/problems/remove-trailing-zeros-from-a-string/
#Given a positive integer num represented as a string, return the integer num without trailing zeros as a string.
# 
#Example 1:
#Input: num = "51230100"
#Output: "512301"
#Explanation: Integer "51230100" has 2 trailing zeros, we remove them and return integer "512301".
#Example 2:
#Input: num = "123"
#Output: "123"
#Explanation: Integer "123" has no trailing zeros, we return integer "123".
# 
#Constraints:
#	1 <= num.length <= 1000
#	num consists of only digits.
#	num doesn't have any leading zeros.
class Solution(object):
    def removeTrailingZeros(self, num):
        """
        :type num: str
        :rtype: str
        """
        # Convert the string to an integer
        num_int = int(num)
        
        # Count the number of trailing zeros in the integer
        zeros = 0
        while num_int % 10 == 0:
            zeros += 1
            num_int //= 10
        
        # Convert the integer back to a string and return
        return str(num_int) + '0' * zeros
        
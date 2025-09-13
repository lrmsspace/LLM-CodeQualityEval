#https://leetcode.com/problems/binary-number-with-alternating-bits/
#Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
# 
#Example 1:
#Input: n = 5
#Output: true
#Explanation: The binary representation of 5 is: 101
#Example 2:
#Input: n = 7
#Output: false
#Explanation: The binary representation of 7 is: 111.
#Example 3:
#Input: n = 11
#Output: false
#Explanation: The binary representation of 11 is: 1011.
# 
#Constraints:
#	1 <= n <= 231 - 1
class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # Convert the number to binary string and remove the '0b' prefix
        binary_str = bin(n)[2:]
        
        # Check if the binary string has alternating bits
        for i in range(1, len(binary_str)):
            if binary_str[i] == binary_str[i - 1]:
                return False
        
        return True        
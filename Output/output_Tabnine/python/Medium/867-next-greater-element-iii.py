#https://leetcode.com/problems/next-greater-element-iii/
#Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
#Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
# 
#Example 1:
#Input: n = 12
#Output: 21
#Example 2:
#Input: n = 21
#Output: -1
# 
#Constraints:
#	1 <= n <= 231 - 1
class Solution(object):
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Convert the integer to a string and reverse it
        num_str = str(n)
        num_str = num_str[::-1]
        
        # Find the first pair of adjacent digits that are in decreasing order
        for i in range(len(num_str) - 1):
            if num_str[i] < num_str[i + 1]:
                # Find the smallest digit from the right that is greater than num_str[i]
                for j in range(len(num_str) - 1, i, -1):
                    if num_str[j] > num_str[i]:
                        # Swap the digits
                        num_str[i], num_str[j] = num_str[j], num_str[i]
                        break
                        
                # Reverse the digits to the right of i
                num_str = num_str[:i + 1] + num_str[i + 1:][::-1]
                
                # Convert the reversed string back to an integer and return
                return int(num_str[::-1])
        
        # If no such pair exists, return -1
        
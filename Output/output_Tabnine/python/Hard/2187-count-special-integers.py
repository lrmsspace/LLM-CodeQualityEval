#https://leetcode.com/problems/count-special-integers/
#We call a positive integer special if all of its digits are distinct.
#Given a positive integer n, return the number of special integers that belong to the interval [1, n].
# 
#Example 1:
#Input: n = 20
#Output: 19
#Explanation: All the integers from 1 to 20, except 11, are special. Thus, there are 19 special integers.
#Example 2:
#Input: n = 5
#Output: 5
#Explanation: All the integers from 1 to 5 are special.
#Example 3:
#Input: n = 135
#Output: 110
#Explanation: There are 110 integers from 1 to 135 that are special.
#Some of the integers that are not special are: 22, 114, and 131.
# 
#Constraints:
#	1 <= n <= 2 * 109
class Solution(object):
    def countSpecialNumbers(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Initialize variables
        count = 0
        digits = 0
        
        # Iterate through all numbers from 1 to n
        for num in range(1, n + 1):
            # Count the number of digits in the current number
            digits = len(str(num))
            
            # Check if the number has distinct digits
            if len(set(str(num))) == digits:
                # Check if the number is special
                if num < 10:
                    count += 1
                elif num < 100:
                    count += 2
                elif num < 1000:
                    count += 3
                elif num < 10000:
                    count += 4
                elif num < 100000:
                    count += 5
                elif num < 1000000:
                    count += 6
                elif num < 10000000:
                    count += 7
        
        return count
        
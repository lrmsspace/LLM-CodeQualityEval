#https://leetcode.com/problems/count-integers-with-even-digit-sum/
#Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.
#The digit sum of a positive integer is the sum of all its digits.
# 
#Example 1:
#Input: num = 4
#Output: 2
#Explanation:
#The only integers less than or equal to 4 whose digit sums are even are 2 and 4.    
#Example 2:
#Input: num = 30
#Output: 14
#Explanation:
#The 14 integers less than or equal to 30 whose digit sums are even are
#2, 4, 6, 8, 11, 13, 15, 17, 19, 20, 22, 24, 26, and 28.
# 
#Constraints:
#	1 <= num <= 1000
class Solution(object):
    def countEven(self, num):
        """
        :type num: int
        :rtype: int
        """
        # Count the number of even digit sums from 0 to num
        count = 0
        for i in range(num + 1):
            # Get the digit sum of the current number
            digit_sum = sum(int(digit) for digit in str(i))
            
            # Check if the digit sum is even
            if digit_sum % 2 == 0:
                count += 1
        
        return count
        
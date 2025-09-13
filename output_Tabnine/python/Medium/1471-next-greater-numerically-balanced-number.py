#https://leetcode.com/problems/next-greater-numerically-balanced-number/
#An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
#Given an integer n, return the smallest numerically balanced number strictly greater than n.
# 
#Example 1:
#Input: n = 1
#Output: 22
#Explanation: 
#22 is numerically balanced since:
#- The digit 2 occurs 2 times. 
#It is also the smallest numerically balanced number strictly greater than 1.
#Example 2:
#Input: n = 1000
#Output: 1333
#Explanation: 
#1333 is numerically balanced since:
#- The digit 1 occurs 1 time.
#- The digit 3 occurs 3 times. 
#It is also the smallest numerically balanced number strictly greater than 1000.
#Note that 1022 cannot be the answer because 0 appeared more than 0 times.
#Example 3:
#Input: n = 3000
#Output: 3133
#Explanation: 
#3133 is numerically balanced since:
#- The digit 1 occurs 1 time.
#- The digit 3 occurs 3 times.
#It is also the smallest numerically balanced number strictly greater than 3000.
# 
#Constraints:
#	0 <= n <= 106
class Solution(object):
    def nextBeautifulNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Convert n to a list of digits
        digits = list(str(n))
        
        # Find the first digit from right to left that is less than its next digit
        i = len(digits) - 2
        while i >= 0 and int(digits[i]) >= int(digits[i + 1]):
            i -= 1
        
        # If no such digit found, return -1
        if i == -1:
            return -1
        
        # Find the first digit from right to left that is greater than the digit at index i
        j = len(digits) - 1
        while j > i and int(digits[j]) <= int(digits[i]):
            j -= 1
        
        # Swap the digits at indices i and j
        digits[i], digits[j] = digits[j], digits[i]
        
        # Reverse the digits from index i + 1 to the end
        digits[i + 1:] = digits[len(digits) - 1:i - 1:-1]
        
        # Convert the list of digits back to an integer
        return int(''.join(digits))
        
#https://leetcode.com/problems/fraction-to-recurring-decimal/
#Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
#If the fractional part is repeating, enclose the repeating part in parentheses.
#If multiple answers are possible, return any of them.
#It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
# 
#Example 1:
#Input: numerator = 1, denominator = 2
#Output: "0.5"
#Example 2:
#Input: numerator = 2, denominator = 1
#Output: "2"
#Example 3:
#Input: numerator = 4, denominator = 333
#Output: "0.(012)"
# 
#Constraints:
#	-231 <= numerator, denominator <= 231 - 1
#	denominator != 0
class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        # Initialize result and sign variables
        result = ""
        sign = "-" if (numerator < 0) ^ (denominator < 0) else ""
        numerator, denominator = abs(numerator), abs(denominator)
        
        # Convert numerator to string
        result += str(numerator // denominator)
        numerator %= denominator
        
        # If numerator is zero, return result with sign
        if numerator == 0:
            return sign + result
        
        # Add decimal point
        result += "."
        
        # Initialize dictionary to store seen remainders
        seen = {}
        
        # Loop until numerator becomes zero
        while numerator!= 0:
            # If remainder is already seen, append parentheses around repeating part
            if numerator in seen:
                result = result[:seen[numerator]] + "(" + result[seen[numerator]:] + ")"
                break
            
            # Store remainder position
            seen[numerator] = len(result)
            
            # Multiply numerator by 10 and get new remainder
            numerator *= 10
            
            # Append new digit to result
            result += str(numerator // denominator)
            
            # Update numerator
            numerator %= denominator
        
        return sign + result
        
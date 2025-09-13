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
        result = []
        if (numerator > 0) ^ (denominator > 0):
            result.append('-')
        n, remainder = divmod(abs(numerator), abs(denominator))
        result.append(str(n))
        if remainder == 0:
            return ''.join(result)
        result.append('.')
        lookup = {}
        while remainder != 0:
            if remainder in lookup:
                start = lookup[remainder]
                result.insert(start, '(')
                result.append(')')
                break
            lookup[remainder] = len(result)
            n, remainder = divmod(remainder * 10, abs(denominator))
            result.append(str(n))
        return ''.join(result)

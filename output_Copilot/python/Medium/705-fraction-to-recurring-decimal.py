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
        if numerator == 0:
            return "0"
        if denominator == 0:
            return "undefined"
        
        res = ""
        if (numerator < 0) ^ (denominator < 0):
            res += "-"
        
        numerator = abs(numerator)
        denominator = abs(denominator)
        
        # 整数部分
        res += str(numerator // denominator)
        
        # 小数部分
        numerator %= denominator
        if numerator == 0:
            return res
        
        res += "."
        
        # 记录小数部分的余数和对应的索引位置
        remainder_map = {}
        
        while numerator != 0:
            if numerator in remainder_map:
                # 找到循环节，插入括号
                index = remainder_map[numerator]
                res = res[:index] + "(" + res[index:] + ")"
                break
            
            remainder_map[numerator] = len(res)
            numerator *= 10
            res += str(numerator // denominator)
            numerator %= denominator
        
        return res        
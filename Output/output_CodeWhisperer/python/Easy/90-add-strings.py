#https://leetcode.com/problems/add-strings/
#Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
#You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
# 
#Example 1:
#Input: num1 = "11", num2 = "123"
#Output: "134"
#Example 2:
#Input: num1 = "456", num2 = "77"
#Output: "533"
#Example 3:
#Input: num1 = "0", num2 = "0"
#Output: "0"
# 
#Constraints:
#	1 <= num1.length, num2.length <= 104
#	num1 and num2 consist of only digits.
#	num1 and num2 don't have any leading zeros except for the zero itself.
class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        res = []
        carry = 0
        p1 = len(num1) - 1
        p2 = len(num2) - 1
        while p1 >= 0 or p2 >= 0:
            x1 = ord(num1[p1]) - ord('0') if p1 >= 0 else 0
            x2 = ord(num2[p2]) - ord('0') if p2 >= 0 else 0
            value = (x1 + x2 + carry) % 10
            carry = (x1 + x2 + carry) // 10
            res.append(value)
            p1 -= 1
            p2 -= 1
        if carry:
            res.append(carry)
        return "".join(str(x) for x in res)[::-1]

        
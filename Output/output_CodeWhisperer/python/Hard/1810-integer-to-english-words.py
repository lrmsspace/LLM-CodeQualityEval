#https://leetcode.com/problems/integer-to-english-words/
#Convert a non-negative integer num to its English words representation.
# 
#Example 1:
#Input: num = 123
#Output: "One Hundred Twenty Three"
#Example 2:
#Input: num = 12345
#Output: "Twelve Thousand Three Hundred Forty Five"
#Example 3:
#Input: num = 1234567
#Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
# 
#Constraints:
#	0 <= num <= 231 - 1
class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return "Zero"
        ones = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
        tens = ["", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        teens = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        thousands = ["", "Thousand", "Million", "Billion"]
        def helper(num):
            if num == 0:
                return ""
            elif num < 10:
                return ones[num] + " "
            elif num < 20:
                return teens[num - 10] + " "
            elif num < 100:
                return tens[num // 10] + " " + helper(num % 10)
            else:
                return ones[num // 100] + " Hundred " + helper(num % 100)
        res = ""
        for i in range(3, -1, -1):
            if num // 1000**i:
                res += helper(num // 1000**i) + thousands[i] + " "
            num %= 1000**i
        return res.strip()
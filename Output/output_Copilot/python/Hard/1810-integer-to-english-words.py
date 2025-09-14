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

        def one(num):
            switch = {
            1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five",
            6: "Six", 7: "Seven", 8: "Eight", 9: "Nine"
            }
            return switch.get(num, "")

        def two_less_20(num):
            switch = {
            10: "Ten", 11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen",
            15: "Fifteen", 16: "Sixteen", 17: "Seventeen", 18: "Eighteen", 19: "Nineteen"
            }
            return switch.get(num, "")

        def ten(num):
            switch = {
            2: "Twenty", 3: "Thirty", 4: "Forty", 5: "Fifty",
            6: "Sixty", 7: "Seventy", 8: "Eighty", 9: "Ninety"
            }
            return switch.get(num, "")

        def two(num):
            if not num:
                return ""
            elif num < 10:
                return one(num)
            elif num < 20:
                return two_less_20(num)
            else:
                tens = num // 10
                rest = num % 10
                return ten(tens) + (" " + one(rest) if rest else "")

        def three(num):
            hundred = num // 100
            rest = num % 100
            if hundred and rest:
                return one(hundred) + " Hundred " + two(rest)
            elif not hundred and rest:
                return two(rest)
            elif hundred and not rest:
                return one(hundred) + " Hundred"
    
        billion = num // 1000000000
        million = (num % 1000000000) // 1000000
        thousand = (num % 1000000) // 1000
        rest = num % 1000

        result = ""
        if billion:
            result += three(billion) + " Billion"
        if million:
            result += " " if result else ""
            result += three(million) + " Million"
        if thousand:
            result += " " if result else ""
            result += three(thousand) + " Thousand"
        if rest:
            result += " " if result else ""
            result += three(rest)
        return result
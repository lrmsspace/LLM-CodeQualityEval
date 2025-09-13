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
        def one(num):
            switcher = {
                1: 'One',
                2: 'Two',
                3: 'Three',
                4: 'Four',
                5: 'Five',
                6: 'Six',
                7: 'Seven',
                8: 'Eight',
                9: 'Nine'
            }
            return switcher.get(num)

        def two_less_20(num):
            switcher = {
                10: 'Ten',
                11: 'Eleven',
                12: 'Twelve',
                13: 'Thirteen',
                14: 'Fourteen',
                15: 'Fifteen',
                16: 'Sixteen',
                17: 'Seventeen',
                18: 'Eighteen',
                19: 'Nineteen'
            }
            return switcher.get(num)

        def ten(num):
            switcher = {
                2: 'Twenty',
                3: 'Thirty',
                4: 'Forty',
                5: 'Fifty',
                6: 'Sixty',
                7: 'Seventy',
                8: 'Eighty',
                9: 'Ninety'
            }
            return switcher.get(num)

        def two(num):
            if not num:
                return ''
            elif num < 10:
                return one(num)
            elif num < 20:
                return two_less_20(num)
            else:
                tens, remainder = divmod(num, 10)
                return ten(tens) + ' ' + one(remainder) if remainder else ten(tens)

        def three(num):
            hundred, remainder = divmod(num, 100)
            if hundred and remainder:
                return one(hundred) + ' Hundred ' + two(remainder)
            elif not hundred and remainder:
                return two(remainder)
            elif hundred and not remainder:
                return one(hundred) + ' Hundred'

        billion, num = divmod(num, 10**9)
        million, num = divmod(num, 10**6)
        thousand, num = divmod(num, 10**3)
        result = ''
        if billion:
            result += three(billion) + ' Billion'
        if million:
            result += ' ' if result else ''
            result += three(million) + ' Million'
        if thousand:
            result += ' ' if result else ''
            result += three(thousand) + ' Thousand'
        if num:
            result += ' ' if result else ''
            result += three(num)
        return result if result else 'Zero'

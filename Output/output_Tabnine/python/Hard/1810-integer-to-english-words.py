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
            return 'Zero'
        
        units = ['', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine']
        teens = ['Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen']
        tens = ['', '', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
        scales = ['', 'Thousand', 'Million', 'Billion']
        
        def convert_under_1000(num):
            if num < 20:
                return teens[num] if num > 10 else units[num]
        
        def convert_range(start, end):
            if start == end:
                return convert_under_1000(start)
            
            mid = (start + end) // 2
            left = convert_range(start, mid)
            right = convert_range(mid + 1, end)
            
            return left +'' + tens[start // 10] +'' + right if left else tens[start // 10] +'' + right
        
        result = []
        for i in range(3, -1, -1):
            quotient, num = divmod(num, 1000)
            if quotient > 0:
                result.append(convert_range(quotient * 100, quotient * 100 + 99))
                result.append(scales[i])
        
        return''.join(result[::-1]).strip()
        
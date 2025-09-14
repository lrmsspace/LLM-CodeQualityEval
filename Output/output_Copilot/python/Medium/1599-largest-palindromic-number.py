#https://leetcode.com/problems/largest-palindromic-number/
#You are given a string num consisting of digits only.
#Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.
#Notes:
#	You do not need to use all the digits of num, but you must use at least one digit.
#	The digits can be reordered.
# 
#Example 1:
#Input: num = "444947137"
#Output: "7449447"
#Explanation: 
#Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
#It can be shown that "7449447" is the largest palindromic integer that can be formed.
#Example 2:
#Input: num = "00009"
#Output: "9"
#Explanation: 
#It can be shown that "9" is the largest palindromic integer that can be formed.
#Note that the integer returned should not contain leading zeroes.
# 
#Constraints:
#	1 <= num.length <= 105
#	num consists of digits.
class Solution(object):
    def largestPalindromic(self, num):
        """
        :type num: str
        :rtype: str
        """
        num = sorted(num, reverse=True)  
        left = []
        right = []
        count = {}
        for digit in num:
            count[digit] = count.get(digit, 0) + 1
        for digit, freq in count.items():
            if freq % 2 == 1:
                left.append(digit)
                freq -= 1
            if freq > 0:
                left.extend([digit] * (freq // 2))
        left.sort(reverse=True)
        right = left.copy()
        right.reverse()
        if len(left) == 0:
            return "0"
        if len(left) % 2 == 1:
            return "".join(left) + "".join(right[1:])
        else:
            return "".join(left) + "".join(right)   
              
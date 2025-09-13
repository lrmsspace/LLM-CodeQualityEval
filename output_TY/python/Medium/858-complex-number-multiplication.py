#https://leetcode.com/problems/complex-number-multiplication/
#A complex number can be represented as a string on the form "real+imaginaryi" where:
#	real is the real part and is an integer in the range [-100, 100].
#	imaginary is the imaginary part and is an integer in the range [-100, 100].
#	i2 == -1.
#Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.
# 
#Example 1:
#Input: num1 = "1+1i", num2 = "1+1i"
#Output: "0+2i"
#Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
#Example 2:
#Input: num1 = "1+-1i", num2 = "1+-1i"
#Output: "0+-2i"
#Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
# 
#Constraints:
#	num1 and num2 are valid complex numbers.
class Solution(object):
    def complexNumberMultiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1 = num1.split('+')
        num2 = num2.split('+')
        real1 = int(num1[0])
        imag1 = int(num1[1][:-1])
        real2 = int(num2[0])
        imag2 = int(num2[1][:-1])
        real = real1*real2 - imag1*imag2
        imag = real1*imag2 + real2*imag1
        return str(real) + '+' + str(imag) + 'i'
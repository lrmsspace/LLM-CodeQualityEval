#https://leetcode.com/problems/minimize-xor/
#Given two positive integers num1 and num2, find the positive integer x such that:
#	x has the same number of set bits as num2, and
#	The value x XOR num1 is minimal.
#Note that XOR is the bitwise XOR operation.
#Return the integer x. The test cases are generated such that x is uniquely determined.
#The number of set bits of an integer is the number of 1's in its binary representation.
# 
#Example 1:
#Input: num1 = 3, num2 = 5
#Output: 3
#Explanation:
#The binary representations of num1 and num2 are 0011 and 0101, respectively.
#The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
#Example 2:
#Input: num1 = 1, num2 = 12
#Output: 3
#Explanation:
#The binary representations of num1 and num2 are 0001 and 1100, respectively.
#The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
# 
#Constraints:
#	1 <= num1, num2 <= 109
class Solution(object):
    def minimizeXor(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        # 计算 num2 的二进制表示中 1 的个数
        count = bin(num2).count("1")
        # 初始化结果为 0
        result = 0
        # 遍历 num1 的每一位
        for i in range(31, -1, -1):
            # 如果当前位在 num1 中是 1，并且我们还需要设置更多的 1，则将该位设置为 1
            if (num1 >> i) & 1 and count > 0:
                result |= (1 << i)
                count -= 1
        # 如果还有剩余的 1，需要从低位开始设置
        for i in range(32):
            if count > 0:
                result |= (1 << i)
                count -= 1
        return result        
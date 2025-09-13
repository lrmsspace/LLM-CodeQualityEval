#https://leetcode.com/problems/sequential-digits/
#An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
#Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
# 
#Example 1:
#Input: low = 100, high = 300
#Output: [123,234]
#Example 2:
#Input: low = 1000, high = 13000
#Output: [1234,2345,3456,4567,5678,6789,12345]
# 
#Constraints:
#	10 <= low <= high <= 10^9
class Solution(object):
    def sequentialDigits(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: List[int]
        """
        # 生成所有的连续数字
        result = []
        for i in range(1, 10):
            num = i
            for j in range(i + 1, 10):
                num = num * 10 + j
                if low <= num <= high:
                    result.append(num)
                elif num > high:
                    break
        return sorted(result)        
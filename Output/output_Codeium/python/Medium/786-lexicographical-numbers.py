#https://leetcode.com/problems/lexicographical-numbers/
#Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
#You must write an algorithm that runs in O(n) time and uses O(1) extra space. 
# 
#Example 1:
#Input: n = 13
#Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
#Example 2:
#Input: n = 2
#Output: [1,2]
# 
#Constraints:
#	1 <= n <= 5 * 104
class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = []
        num = 1
        for _ in range(n):
            res.append(num)
            if num * 10 <= n:
                num *= 10
            elif num + 1 <= n:
                num += 1
            else:
                tmp = num
                while tmp % 10 == 9:
                    tmp //= 10
                num = tmp + 1
        return res

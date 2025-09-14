#https://leetcode.com/problems/count-largest-group/
#You are given an integer n.
#Each number from 1 to n is grouped according to the sum of its digits.
#Return the number of groups that have the largest size.
# 
#Example 1:
#Input: n = 13
#Output: 4
#Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
#[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
#There are 4 groups with largest size.
#Example 2:
#Input: n = 2
#Output: 2
#Explanation: There are 2 groups [1], [2] of size 1.
# 
#Constraints:
#	1 <= n <= 104
class Solution(object):
    def countLargestGroup(self, n):
        """
        :type n: int
        :rtype: int
        """
        def sum_digits(num):
            sum = 0
            while num > 0:
                sum += num % 10
                num = num // 10
            return sum
        
        groups = {}
        for i in range(1, n + 1):
            sum = sum_digits(i)
            if sum in groups:
                groups[sum].append(i)
            else:
                groups[sum] = [i]
        
        max_size = 0
        for group in groups.values():
            max_size = max(max_size, len(group))
        
        count = 0
        for group in groups.values():
            if len(group) == max_size:
                count += 1
        
        return count
        
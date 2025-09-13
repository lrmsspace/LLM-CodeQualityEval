#https://leetcode.com/problems/longest-well-performing-interval/
#We are given hours, a list of the number of hours worked per day for a given employee.
#A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.
#A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.
#Return the length of the longest well-performing interval.
# 
#Example 1:
#Input: hours = [9,9,6,0,6,6,9]
#Output: 3
#Explanation: The longest well-performing interval is [9,9,6].
#Example 2:
#Input: hours = [6,6,6]
#Output: 0
# 
#Constraints:
#	1 <= hours.length <= 104
#	0 <= hours[i] <= 16
class Solution(object):
    def longestWPI(self, hours):
        """
        :type hours: List[int]
        :rtype: int
        """
        n = len(hours)
        prefix_sum = [0] * (n + 1)
        for i in range(n):
            prefix_sum[i + 1] = prefix_sum[i] + (1 if hours[i] > 8 else -1)

        stack = []
        max_length = 0

        for i in range(n + 1):
            if not stack or prefix_sum[i] < prefix_sum[stack[-1]]:
                stack.append(i)

        for i in range(n, -1, -1):
            while stack and prefix_sum[i] > prefix_sum[stack[-1]]:
                max_length = max(max_length, i - stack.pop())

        return max_length        
#https://leetcode.com/problems/beautiful-array/
#An array nums of length n is beautiful if:
#	nums is a permutation of the integers in the range [1, n].
#	For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
#Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.
# 
#Example 1:
#Input: n = 4
#Output: [2,1,4,3]
#Example 2:
#Input: n = 5
#Output: [3,1,2,5,4]
# 
#Constraints:
#	1 <= n <= 1000
class Solution(object):
    def beautifulArray(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        def dfs(left, right, path):
            if left > right:
                return [path + [right]]
            result = []
            for num in range(left, right + 1, 2):
                result += dfs(left, num - 1, path + [num])
            for num in range(right, left - 1, -2):
                result += dfs(num + 1, right, path + [num])
            return result
        
        return dfs(1, n, [])
        
#https://leetcode.com/problems/largest-component-size-by-common-factor/
#You are given an integer array of unique positive integers nums. Consider the following graph:
#	There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
#	There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
#Return the size of the largest connected component in the graph.
# 
#Example 1:
#Input: nums = [4,6,15,35]
#Output: 4
#Example 2:
#Input: nums = [20,50,9,63]
#Output: 2
#Example 3:
#Input: nums = [2,3,6,7,4,12,21,39]
#Output: 8
# 
#Constraints:
#	1 <= nums.length <= 2 * 104
#	1 <= nums[i] <= 105
#	All the values of nums are unique.
class Solution(object):
    def largestComponentSize(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def prime_factors(n):
            i = 2
            factors = set()
            while i * i <= n:
                if n % i:
                    i += 1
                else:
                    n //= i
                    factors.add(i)
            if n > 1:
                factors.add(n)
            return factors

        uf = {}
        def find(x):
            if x not in uf:
                uf[x] = x
            if uf[x] != x:
                uf[x] = find(uf[x])
            return uf[x]

        def union(x, y):
            uf[find(x)] = find(y)

        for x in nums:
            for y in prime_factors(x):
                if y != x:
                    union(x, y)

        count = collections.Counter(find(x) for x in nums)
        return max(count.values())

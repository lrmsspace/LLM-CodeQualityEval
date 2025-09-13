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
        from collections import defaultdict
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                parent[rootY] = rootX

        max_num = max(nums)
        parent = [i for i in range(max_num + 1)]
        prime_to_index = defaultdict(list)

        for i, num in enumerate(nums):
            for j in range(2, int(num**0.5) + 1):
                if num % j == 0:
                    prime_to_index[j].append(i)
                    while num % j == 0:
                        num //= j
            if num > 1:
                prime_to_index[num].append(i)

        for indices in prime_to_index.values():
            first_index = indices[0]
            for index in indices[1:]:
                union(first_index, index)

        component_size = defaultdict(int)
        for i in range(len(nums)):
            root = find(i)
            component_size[root] += 1

        return max(component_size.values())        
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
        # Create a map to store the prime factors of each number
        factors = {num: [] for num in nums}
        
        # Sieve of Eratosthenes to find prime factors
        primes = [True] * (10**5 + 1)
        primes[0] = primes[1] = False
        for i in range(2, int(10**5**0.5) + 1):
            if primes[i]:
                for j in range(i*i, 10**5 + 1, i):
                    primes[j] = False
        
        # Find prime factors for each number
        for num in nums:
            if primes[num]:
                factors[num].append(num)
            else:
                divisor = 2
                while divisor * divisor <= num:
                    if num % divisor == 0:
                        factors[num].append(divisor)
        
        # Union-Find data structure to find connected components
        parent = list(range(len(nums)))
        def find(x):
            if parent[x]!= x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x, y):
            parent[find(x)] = find(y)
        
        # Union components based on prime factors
        for num in nums:
            for factor in factors[num]:
                union(num, factor)
        
        # Count size of each connected component
        component_sizes = [0] * len(nums)
        for i in range(len(nums)):
            component_sizes[find(i)] += 1
        
        # Return size of the largest connected component
        return max(component_sizes)
        
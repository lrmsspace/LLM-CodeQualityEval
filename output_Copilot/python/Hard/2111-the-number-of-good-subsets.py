#https://leetcode.com/problems/the-number-of-good-subsets/
#You are given an integer array nums. We call a subset of nums good if its product can be represented as a product of one or more distinct prime numbers.
#	For example, if nums = [1, 2, 3, 4]:
#	
#		[2, 3], [1, 2, 3], and [1, 3] are good subsets with products 6 = 2*3, 6 = 2*3, and 3 = 3 respectively.
#		[1, 4] and [4] are not good subsets with products 4 = 2*2 and 4 = 2*2 respectively.
#	
#	
#Return the number of different good subsets in nums modulo 109 + 7.
#A subset of nums is any array that can be obtained by deleting some (possibly none or all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.
# 
#Example 1:
#Input: nums = [1,2,3,4]
#Output: 6
#Explanation: The good subsets are:
#- [1,2]: product is 2, which is the product of distinct prime 2.
#- [1,2,3]: product is 6, which is the product of distinct primes 2 and 3.
#- [1,3]: product is 3, which is the product of distinct prime 3.
#- [2]: product is 2, which is the product of distinct prime 2.
#- [2,3]: product is 6, which is the product of distinct primes 2 and 3.
#- [3]: product is 3, which is the product of distinct prime 3.
#Example 2:
#Input: nums = [4,2,3,15]
#Output: 5
#Explanation: The good subsets are:
#- [2]: product is 2, which is the product of distinct prime 2.
#- [2,3]: product is 6, which is the product of distinct primes 2 and 3.
#- [2,15]: product is 30, which is the product of distinct primes 2, 3, and 5.
#- [3]: product is 3, which is the product of distinct prime 3.
#- [15]: product is 15, which is the product of distinct primes 3 and 5.
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 30
class Solution(object):
    def numberOfGoodSubsets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import Counter
        from functools import reduce
        from math import gcd

        # 计算质数的乘积
        def prime_product(num):
            primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
            product = 1
            for prime in primes:
                if num % prime == 0:
                    product *= prime
                    num //= prime
            return product

        # 计算最大公约数的质因数乘积
        def gcd_prime_product(a, b):
            return reduce(lambda x, y: x * y if gcd(x, y) == x else x * y // gcd(x, y), [a, b])

        count = Counter(nums)
        result = 1

        # 遍历所有数字，计算质数乘积并更新结果
        for num in range(1, 31):
            if count[num] > 0:
                result *= (count[num] + 1)

        return result - 1 if result > 0 else result        
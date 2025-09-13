#https://leetcode.com/problems/super-pow/
#Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
# 
#Example 1:
#Input: a = 2, b = [3]
#Output: 8
#Example 2:
#Input: a = 2, b = [1,0]
#Output: 1024
#Example 3:
#Input: a = 1, b = [4,3,3,8,5,2]
#Output: 1
# 
#Constraints:
#	1 <= a <= 231 - 1
#	1 <= b.length <= 2000
#	0 <= b[i] <= 9
#	b does not contain leading zeros.
class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        def mod_pow(x, n, mod):
            if n == 0:
                return 1
            half = mod_pow(x, n // 2, mod)
            half = (half * half) % mod
            if n % 2 != 0:
                half = (half * x) % mod
            return half

        mod = 1337
        result = 1
        for digit in b:
            result = mod_pow(result, 10, mod) * mod_pow(a, digit, mod) % mod
        return result


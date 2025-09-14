#https://leetcode.com/problems/three-divisors/
#Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.
#An integer m is a divisor of n if there exists an integer k such that n = k * m.
# 
#Example 1:
#Input: n = 2
#Output: false
#Explantion: 2 has only two divisors: 1 and 2.
#Example 2:
#Input: n = 4
#Output: true
#Explantion: 4 has three divisors: 1, 2, and 4.
# 
#Constraints:
#	1 <= n <= 104
class Solution(object):
    def isThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n < 4:
            return n == 2 or n == 3
        
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                if i * i == n or (n // i) * i == n:
                    return True
        
        return False
        
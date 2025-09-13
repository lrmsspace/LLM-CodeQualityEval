#https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/
#You are given a positive integer n, you can do the following operation any number of times:
#	Add or subtract a power of 2 from n.
#Return the minimum number of operations to make n equal to 0.
#A number x is power of 2 if x == 2i where i >= 0.
# 
#Example 1:
#Input: n = 39
#Output: 3
#Explanation: We can do the following operations:
#- Add 20 = 1 to n, so now n = 40.
#- Subtract 23 = 8 from n, so now n = 32.
#- Subtract 25 = 32 from n, so now n = 0.
#It can be shown that 3 is the minimum number of operations we need to make n equal to 0.
#Example 2:
#Input: n = 54
#Output: 3
#Explanation: We can do the following operations:
#- Add 21 = 2 to n, so now n = 56.
#- Add 23 = 8 to n, so now n = 64.
#- Subtract 26 = 64 from n, so now n = 0.
#So the minimum number of operations is 3.
# 
#Constraints:
#	1 <= n <= 105
class Solution(object):
    def minOperations(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Initialize a counter for the number of operations
        count = 0
        
        # While n is not 0, keep subtracting powers of 2 from n
        while n > 0:
            # If n is an odd number, subtract 1 from n
            if n & 1:
                n -= 1
            else:
                # If n is even, subtract the largest power of 2 less than or equal to n
                n >>= 1
            
            # Increment the counter for the number of operations
            count += 1
        
        return count
        
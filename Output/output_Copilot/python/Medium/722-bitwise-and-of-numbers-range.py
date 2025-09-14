#https://leetcode.com/problems/bitwise-and-of-numbers-range/
#Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
# 
#Example 1:
#Input: left = 5, right = 7
#Output: 4
#Example 2:
#Input: left = 0, right = 0
#Output: 0
#Example 3:
#Input: left = 1, right = 2147483647
#Output: 0
# 
#Constraints:
#	0 <= left <= right <= 231 - 1
class Solution(object):
    def rangeBitwiseAnd(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        # 1. Initialize the result to 0
        result = 0
        
        # 2. Iterate through the bits from the most significant bit to the least significant bit
        for i in range(31, -1, -1):
            # 3. Check if the left and right numbers have the same value at the current bit position
            if (left >> i) == (right >> i):
                # 4. If they are the same, set that bit in the result
                result |= (left >> i) << i
            else:
                # 5. If they are different, break out of the loop
                break
        
        return result        
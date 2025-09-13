#https://leetcode.com/problems/circular-permutation-in-binary-representation/
#Given 2 integers n and start. Your task is return any permutation p of (0,1,2.....,2^n -1) such that :
#	p[0] = start
#	p[i] and p[i+1] differ by only one bit in their binary representation.
#	p[0] and p[2^n -1] must also differ by only one bit in their binary representation.
# 
#Example 1:
#Input: n = 2, start = 3
#Output: [3,2,0,1]
#Explanation: The binary representation of the permutation is (11,10,00,01). 
#All the adjacent element differ by one bit. Another valid permutation is [3,1,0,2]
#Example 2:
#Input: n = 3, start = 2
#Output: [2,6,7,5,4,0,1,3]
#Explanation: The binary representation of the permutation is (010,110,111,101,100,000,001,011).
# 
#Constraints:
#	1 <= n <= 16
#	0 <= start < 2 ^ n
class Solution(object):

    def circularPermutation(self, n, start):

        """

        :type n: int

        :type start: int

        :rtype: List[int]

        """
        # Generate the Gray code sequence for n bits
        gray_code = [i ^ (i >> 1) for i in range(1 << n)]

        # Find the index of the start value in the Gray code sequence
        start_index = gray_code.index(start)

        # Rotate the Gray code sequence to start from the given start value
        return gray_code[start_index:] + gray_code[:start_index]
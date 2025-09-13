#https://leetcode.com/problems/permutation-sequence/
#The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
#By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
#	"123"
#	"132"
#	"213"
#	"231"
#	"312"
#	"321"
#Given n and k, return the kth permutation sequence.
# 
#Example 1:
#Input: n = 3, k = 3
#Output: "213"
#Example 2:
#Input: n = 4, k = 9
#Output: "2314"
#Example 3:
#Input: n = 3, k = 1
#Output: "123"
# 
#Constraints:
#	1 <= n <= 9
#	1 <= k <= n!
class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        # 1. Create a list of numbers to get permutations from.
        nums = [str(i) for i in range(1, n + 1)]

        # 2. Calculate the factorial of (n-1) to determine the size of each block.
        fact = 1
        for i in range(1, n):
            fact *= i

        # 3. Adjust k to be zero-indexed.
        k -= 1

        # 4. Initialize an empty string to build the result.
        result = ""

        # 5. Generate the permutation sequence.
        for i in range(n):
            index = k // fact
            result += nums[index]
            nums.pop(index)

            if i < n - 1:
                k %= fact
                fact //= (n - i - 1)

        return result        
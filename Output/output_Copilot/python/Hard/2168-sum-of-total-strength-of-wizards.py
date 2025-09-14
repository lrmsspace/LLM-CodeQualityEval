#https://leetcode.com/problems/sum-of-total-strength-of-wizards/
#As the ruler of a kingdom, you have an army of wizards at your command.
#You are given a 0-indexed integer array strength, where strength[i] denotes the strength of the ith wizard. For a contiguous group of wizards (i.e. the wizards' strengths form a subarray of strength), the total strength is defined as the product of the following two values:
#	The strength of the weakest wizard in the group.
#	The total of all the individual strengths of the wizards in the group.
#Return the sum of the total strengths of all contiguous groups of wizards. Since the answer may be very large, return it modulo 109 + 7.
#A subarray is a contiguous non-empty sequence of elements within an array.
# 
#Example 1:
#Input: strength = [1,3,1,2]
#Output: 44
#Explanation: The following are all the contiguous groups of wizards:
#- [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
#- [3] from [1,3,1,2] has a total strength of min([3]) * sum([3]) = 3 * 3 = 9
#- [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
#- [2] from [1,3,1,2] has a total strength of min([2]) * sum([2]) = 2 * 2 = 4
#- [1,3] from [1,3,1,2] has a total strength of min([1,3]) * sum([1,3]) = 1 * 4 = 4
#- [3,1] from [1,3,1,2] has a total strength of min([3,1]) * sum([3,1]) = 1 * 4 = 4
#- [1,2] from [1,3,1,2] has a total strength of min([1,2]) * sum([1,2]) = 1 * 3 = 3
#- [1,3,1] from [1,3,1,2] has a total strength of min([1,3,1]) * sum([1,3,1]) = 1 * 5 = 5
#- [3,1,2] from [1,3,1,2] has a total strength of min([3,1,2]) * sum([3,1,2]) = 1 * 6 = 6
#- [1,3,1,2] from [1,3,1,2] has a total strength of min([1,3,1,2]) * sum([1,3,1,2]) = 1 * 7 = 7
#The sum of all the total strengths is 1 + 9 + 1 + 4 + 4 + 4 + 3 + 5 + 6 + 7 = 44.
#Example 2:
#Input: strength = [5,4,6]
#Output: 213
#Explanation: The following are all the contiguous groups of wizards: 
#- [5] from [5,4,6] has a total strength of min([5]) * sum([5]) = 5 * 5 = 25
#- [4] from [5,4,6] has a total strength of min([4]) * sum([4]) = 4 * 4 = 16
#- [6] from [5,4,6] has a total strength of min([6]) * sum([6]) = 6 * 6 = 36
#- [5,4] from [5,4,6] has a total strength of min([5,4]) * sum([5,4]) = 4 * 9 = 36
#- [4,6] from [5,4,6] has a total strength of min([4,6]) * sum([4,6]) = 4 * 10 = 40
#- [5,4,6] from [5,4,6] has a total strength of min([5,4,6]) * sum([5,4,6]) = 4 * 15 = 60
#The sum of all the total strengths is 25 + 16 + 36 + 36 + 40 + 60 = 213.
# 
#Constraints:
#	1 <= strength.length <= 105
#	1 <= strength[i] <= 109
class Solution(object):
    def totalStrength(self, strength):
        """
        :type strength: List[int]
        :rtype: int
        """
        n = len(strength)
        mod = 10**9 + 7
        prefix_sum = [0] * (n + 1)
        for i in range(n):
            prefix_sum[i + 1] = (prefix_sum[i] + strength[i]) % mod

        stack = []
        left = [0] * n
        right = [0] * n

        for i in range(n):
            while stack and strength[stack[-1]] > strength[i]:
                stack.pop()
            left[i] = stack[-1] if stack else -1
            stack.append(i)

        stack = []
        for i in range(n - 1, -1, -1):
            while stack and strength[stack[-1]] >= strength[i]:
                stack.pop()
            right[i] = stack[-1] if stack else n
            stack.append(i)

        result = 0
        for i in range(n):
            l, r = left[i], right[i]
            sum_strength = (prefix_sum[r] - prefix_sum[l + 1]) % mod
            result += (sum_strength * strength[i]) % mod
            result %= mod

        return result        
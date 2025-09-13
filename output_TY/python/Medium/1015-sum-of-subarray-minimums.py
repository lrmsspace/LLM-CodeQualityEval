#https://leetcode.com/problems/sum-of-subarray-minimums/
#Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
# 
#Example 1:
#Input: arr = [3,1,2,4]
#Output: 17
#Explanation: 
#Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
#Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
#Sum is 17.
#Example 2:
#Input: arr = [11,81,94,43,3]
#Output: 444
# 
#Constraints:
#	1 <= arr.length <= 3 * 104
#	1 <= arr[i] <= 3 * 104
class Solution(object):
    def sumSubarrayMins(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        mod = 10**9 + 7
        n = len(arr)
        left = [0] * n
        stack = []
        for i in range(n):
            count = 1
            while stack and stack[-1][0] >= arr[i]:
                count += stack.pop()[1]
            left[i] = count
            stack.append([arr[i], count])
        right = [0] * n
        stack = []
        for i in range(n - 1, -1, -1):
            count = 1
            while stack and stack[-1][0] > arr[i]:
                count += stack.pop()[1]
            right[i] = count
            stack.append([arr[i], count])
        ans = 0
        for i in range(n):
            ans += (left[i] * right[i] * arr[i]) % mod
            ans %= mod
        
        return ans

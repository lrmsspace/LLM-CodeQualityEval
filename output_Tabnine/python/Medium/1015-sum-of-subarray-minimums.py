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
        MOD = 10**9 + 7
        n = len(arr)
        stack = []
        left = [0]*n
        right = [0]*n
        prefix_product = [1]*n
        
        for i in range(n):
            while stack and arr[stack[-1]] > arr[i]:
                stack.pop()
            left[i] = stack[-1] if stack else -1
            stack.append(i)
        
        stack = []
        for i in range(n-1, -1, -1):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            right[i] = stack[-1] if stack else n
            stack.append(i)
        
        for i in range(n):
            prefix_product[i] = (prefix_product[i-1] * arr[i]) % MOD
        
        ans = 0
        for i in range(n):
            ans = (ans + arr[i] * (i - left[i]) * (right[i] - i) * prefix_product[i]) % MOD
        return ans
        
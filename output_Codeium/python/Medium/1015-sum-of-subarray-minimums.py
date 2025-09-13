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
        stack = []
        result = 0
        current_sum = 0
        
        for i, x in enumerate(arr):
            count = 1
            while stack and stack[-1][0] > x:
                val, cnt = stack.pop()
                current_sum -= val * cnt
                count += cnt
            stack.append((x, count))
            current_sum += x * count
            result += current_sum
            result %= MOD
        
        return result


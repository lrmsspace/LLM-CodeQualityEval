#https://leetcode.com/problems/make-array-strictly-increasing/
#Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
#In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
#If there is no way to make arr1 strictly increasing, return -1.
# 
#Example 1:
#Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
#Output: 1
#Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
#Example 2:
#Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
#Output: 2
#Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
#Example 3:
#Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
#Output: -1
#Explanation: You can't make arr1 strictly increasing.
# 
#Constraints:
#	1 <= arr1.length, arr2.length <= 2000
#	0 <= arr1[i], arr2[i] <= 10^9
# 
class Solution(object):
    def makeArrayIncreasing(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        # Remove duplicates and sort arr2
        arr2 = sorted(set(arr2))
        
        # dp[i][j] represents the minimum value possible at index i 
        # after j operations to make arr1[0:i+1] strictly increasing
        dp = {}
        
        def dfs(i, prev):
            if i >= len(arr1):
                return 0
                
            if (i, prev) in dp:
                return dp[(i, prev)]
            
            # Cost if we don't replace current element
            cost = float('inf')
            if arr1[i] > prev:
                cost = dfs(i + 1, arr1[i])
            
            # Cost if we replace current element
            # Find the smallest number in arr2 that is greater than prev
            idx = bisect.bisect_right(arr2, prev)
            if idx < len(arr2):
                cost = min(cost, 1 + dfs(i + 1, arr2[idx]))
                
            dp[(i, prev)] = cost
            return cost
        
        result = dfs(0, float('-inf'))
        return result if result != float('inf') else -1
    
            
#https://leetcode.com/problems/non-decreasing-subsequences/
#Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
# 
#Example 1:
#Input: nums = [4,6,7,7]
#Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
#Example 2:
#Input: nums = [4,4,3,2,1]
#Output: [[4,4]]
# 
#Constraints:
#	1 <= nums.length <= 15
#	-100 <= nums[i] <= 100
class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # Initialize the result set and the visited set
        result, visited = set(), set()
        
        # Recursive function to find all subsequences
        def dfs(index, path):
            # Add the current path to the result set
            if len(path) >= 2:
                result.add(tuple(path))
            
            # Iterate over the remaining elements
            for i in range(index, len(nums)):
                # Skip duplicate elements
                if i > index and nums[i] == nums[i-1]:
                    continue
                
                # Add the current element to the path and mark it as visited
                path.append(nums[i])
                visited.add(nums[i])
                
                # Recursively find all subsequences starting from the next index
                dfs(i+1, path)
                
                # Remove the current element from the path and mark it as unvisited
                path.pop()
                visited.remove(nums[i])
        
        # Start the recursive DFS from the first index
        dfs(0, [])
        
        # Convert the result set to a list of lists
        return list(result)
        
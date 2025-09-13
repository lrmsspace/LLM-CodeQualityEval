#https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
#There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.
#You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.
#It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.
#Return the original array nums. If there are multiple solutions, return any of them.
# 
#Example 1:
#Input: adjacentPairs = [[2,1],[3,4],[3,2]]
#Output: [1,2,3,4]
#Explanation: This array has all its adjacent pairs in adjacentPairs.
#Notice that adjacentPairs[i] may not be in left-to-right order.
#Example 2:
#Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
#Output: [-2,4,1,-3]
#Explanation: There can be negative numbers.
#Another solution is [-3,1,4,-2], which would also be accepted.
#Example 3:
#Input: adjacentPairs = [[100000,-100000]]
#Output: [100000,-100000]
# 
#Constraints:
#	nums.length == n
#	adjacentPairs.length == n - 1
#	adjacentPairs[i].length == 2
#	2 <= n <= 105
#	-105 <= nums[i], ui, vi <= 105
#	There exists some nums that has adjacentPairs as its pairs.
class Solution(object):
    def restoreArray(self, adjacentPairs):
        """
        :type adjacentPairs: List[List[int]]
        :rtype: List[int]
        """
        # Create a dictionary to store the adjacent pairs
        adj_dict = defaultdict(list)
        for pair in adjacentPairs:
            adj_dict[pair[0]].append(pair[1])
            adj_dict[pair[1]].append(pair[0])
        
        # Find the start of the array
        start = None
        for num, adj in adj_dict.items():
            if len(adj) == 1:
                start = num
                break
        
        # Reconstruct the array
        result = [start]
        while len(result) < len(adjacentPairs) + 1:
            last = result[-1]
            next_num = adj_dict[last][0] if adj_dict[last][0] != result[-2] else adj_dict[last][1]
            result.append(next_num)
        
        return result
        
#https://leetcode.com/problems/combination-sum-ii/
#Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
#Each number in candidates may only be used once in the combination.
#Note: The solution set must not contain duplicate combinations.
# 
#Example 1:
#Input: candidates = [10,1,2,7,6,1,5], target = 8
#Output: 
#[
#[1,1,6],
#[1,2,5],
#[1,7],
#[2,6]
#]
#Example 2:
#Input: candidates = [2,5,2,1,2], target = 5
#Output: 
#[
#[1,2,2],
#[5]
#]
# 
#Constraints:
#	1 <= candidates.length <= 100
#	1 <= candidates[i] <= 50
#	1 <= target <= 30
class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def backtrack(start, path, remain):
            if remain == 0:
                result.append(path[:])
                return
            
            for i in range(start, len(candidates)):
                if i > start and candidates[i] == candidates[i-1]:
                    continue
                if candidates[i] > remain:
                    break
                backtrack(i+1, path+[candidates[i]], remain-candidates[i])
        
        result = []
        candidates.sort()
        backtrack(0, [], target)
        return result
        
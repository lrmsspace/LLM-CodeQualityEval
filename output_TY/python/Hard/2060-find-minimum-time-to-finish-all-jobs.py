#https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
#You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.
#There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.
#Return the minimum possible maximum working time of any assignment. 
# 
#Example 1:
#Input: jobs = [3,2,3], k = 3
#Output: 3
#Explanation: By assigning each person one job, the maximum time is 3.
#Example 2:
#Input: jobs = [1,2,4,7,8], k = 2
#Output: 11
#Explanation: Assign the jobs the following way:
#Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
#Worker 2: 4, 7 (working time = 4 + 7 = 11)
#The maximum working time is 11.
# 
#Constraints:
#	1 <= k <= jobs.length <= 12
#	1 <= jobs[i] <= 107
class Solution(object):
    def minimumTimeRequired(self, jobs, k):
        """
        :type jobs: List[int]
        :type k: int
        :rtype: int
        """
        n = len(jobs)
        dp = [[0] * (1 << n) for _ in range(k + 1)]
        max_mask = (1 << n) - 1
        for i in range(1, k + 1):
            for mask in range(max_mask + 1):
                if mask == 0:
                    dp[i][mask] = float('inf')
                    continue
                sub_mask = mask
                while sub_mask:
                    dp[i][mask] = min(dp[i][mask], max(dp[i - 1][mask - sub_mask], sum(jobs[j] for j in range(n) if (1 << j) & sub_mask)))
                    sub_mask = (sub_mask - 1) & mask
        return dp[k][max_mask]